#include "model_nodes.hpp"

#include <cstdlib>

ERR_MODEL_NODES err_conv_p2mn(const ERR_POINT_3D rc_p)
{
    ERR_MODEL_NODES rc_mn;

    switch (rc_p)
    {
        case ERR_POINT_3D_OKAY:
            rc_mn = ERR_MODEL_NODES_OKAY;
            break;
        case ERR_POINT_3D_INCOR_FILE:
            rc_mn = ERR_MODEL_NODES_FILE_INCOR;
            break;
        case ERR_POINT_3D_FILE_NULL:
            rc_mn = ERR_MODEL_NODES_FILE_NULL;
            break;
    }

    return rc_mn;
}

model_nodes model_nodes_empty()
{
    return { nullptr, 0 };
}

bool model_nodes_is_empty(const model_nodes &nodes)
{
    return nullptr == nodes.data || 0 == nodes.len;
}

ERR_MODEL_NODES model_nodes_load(model_nodes &nodes, FILE *f)
{
    model_nodes nodes_tmp = model_nodes_empty();

    if (1 != fscanf(f, "%d", &nodes_tmp.len) || nodes_tmp.len < 0)
        return ERR_MODEL_NODES_FILE_INCOR;

    if (ERR_MODEL_NODES_OKAY != model_nodes_alloc(nodes_tmp))
        return ERR_MODEL_NODES_ALLOC_FAILED;

    if (ERR_MODEL_NODES_OKAY != model_nodes_fscan(nodes_tmp, nodes_tmp.len, f))
    {
        model_nodes_clear(nodes_tmp);
        return ERR_MODEL_NODES_FILE_INCOR;
    }

    nodes = nodes_tmp;

    return ERR_MODEL_NODES_OKAY;
}

ERR_MODEL_NODES model_nodes_fscan(model_nodes &nodes, int nodes_count, FILE *f)
{
    ERR_POINT_3D rc_point = ERR_POINT_3D_OKAY;

    for (int i = 0; i < nodes_count && ERR_POINT_3D_OKAY == rc_point; ++i)
        rc_point = point_3D_fscan(nodes.data[i], f);

    return err_conv_p2mn(rc_point);
}

void model_nodes_clear(model_nodes &nodes)
{
    free(nodes.data);

    nodes = model_nodes_empty();
}

ERR_MODEL_NODES model_nodes_scale(model_nodes &nodes,
                                  const model_scale_data_t &scale_data)
{
    if (model_nodes_is_empty(nodes))
        return ERR_MODEL_NODES_IS_EMPTY;

    for (size_t i = 0; i < nodes.len; ++i)
        point_3d_scale_by_0(nodes.data[i], scale_data.coefficients);

    return ERR_MODEL_NODES_OKAY;
}

ERR_MODEL_NODES model_nodes_rotate(model_nodes &nodes,
                                   const model_rotate_data_t &rotate_data)
{
    if (model_nodes_is_empty(nodes))
        return ERR_MODEL_NODES_IS_EMPTY;

    for (size_t i = 0; i < nodes.len; ++i)
        point_3d_rotate_by_0(nodes.data[i], rotate_data.angles);

    return ERR_MODEL_NODES_OKAY;
}

ERR_MODEL_NODES model_nodes_alloc(model_nodes &nodes)
{
    ERR_MODEL_NODES rc = ERR_MODEL_NODES_OKAY;

    point_3D *nodes_mem = (point_3D *) malloc(sizeof(point_3D) * nodes.len);

    if (nullptr != nodes_mem)
        nodes.data = nodes_mem;
    else
        rc = ERR_MODEL_NODES_ALLOC_FAILED;

    return rc;
}

point_2D model_node_to_point_2d(const point_3D & point,
                                const point_3D & center)
{
    return { point.x + center.x, point.y + center.y };
}

