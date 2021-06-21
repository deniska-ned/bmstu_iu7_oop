#include "model.hpp"

#include <iostream>
void model_output(model model);

#include <cstdio>
#include <cassert>

#include "qt_model_drawer.hpp"
#include "model_errors.hpp"

ERR_MODEL_PROXY err_conv_mn2m(const ERR_MODEL_NODES mn_rc)
{
    ERR_MODEL_PROXY m_rc;

    switch (mn_rc)
    {
        case ERR_MODEL_NODES_OKAY:
            m_rc = ERR_MODEL_OKAY;
            break;
        case ERR_MODEL_NODES_FILE_INCOR:
            m_rc = ERR_MODEL_FILE_INCOR;
            break;
        case ERR_MODEL_NODES_ALLOC_FAILED:
            m_rc = ERR_MODEL_ALLOC_FAILED;
            break;
        case ERR_MODEL_NODES_IS_EMPTY:
            m_rc = ERR_MODEL_IS_EMPTY;
            break;
        case ERR_MODEL_NODES_FILE_NULL:
            m_rc = ERR_MODEL_FILE_NULL;
            break;
    }

    return m_rc;
}

ERR_MODEL_PROXY err_conv_me2m(const ERR_MODEL_EDGES me_rc)
{
    ERR_MODEL_PROXY m_rc;

    switch (me_rc)
    {
        case ERR_MODEL_EDGES_OKAY:
            m_rc = ERR_MODEL_OKAY;
            break;
        case ERR_MODEL_EDGES_FILE_INCOR:
            m_rc = ERR_MODEL_FILE_INCOR;
            break;
        case ERR_MODEL_EDGES_ALLOC_FAILED:
            m_rc = ERR_MODEL_ALLOC_FAILED;
            break;
        case ERR_MODEL_EDGES_FILE_NULL:
            m_rc = ERR_MODEL_FILE_NULL;
            break;
    }

    return m_rc;
}

struct model model_init_empty()
{
    struct point_3D center = point_3d_get_0();

    model model = {
            .center = center,
            .nodes = model_nodes_empty(),
            .edges = model_edges_empty()
    };

    return model;
}

bool model_is_empty(const model &model)
{
    return model_nodes_is_empty(model.nodes)
           || model_edges_is_empty(model.edges);
}

ERR_MODEL_PROXY model_file_load(struct model &model, FILE *f)
{
    ERR_MODEL_PROXY rc = ERR_MODEL_OKAY;

    struct model model_tmp = model_init_empty();

    if (ERR_POINT_3D_OKAY != point_3D_fscan(model_tmp.center, f))
        rc = ERR_MODEL_FILE_INCOR;
    else
    {
        ERR_MODEL_NODES rc_nodes = model_nodes_load(model_tmp.nodes, f);
        rc = err_conv_mn2m(rc_nodes);
        if (ERR_MODEL_OKAY == rc)
        {
            ERR_MODEL_EDGES rc_edges = model_edges_load(model_tmp.edges, f);
            rc = err_conv_me2m(rc_edges);
            if (ERR_MODEL_OKAY != rc)
                model_nodes_clear(model_tmp.nodes);
        }
    }

    if (ERR_MODEL_OKAY == rc)
    {
        model_clear(model);
        model = model_tmp;
    }

    return rc;
}

ERR_MODEL_PROXY
model_file_load(struct model &model, const model_file_init_t &file_data)
{
    ERR_MODEL_PROXY rc;

    FILE *f = fopen(file_data.filename, "r");

    if (!f)
        rc = ERR_MODEL_FILE_CANNOT_BE_OPENED;
    else
    {
        rc = model_file_load(model, f);
        fclose(f);
    }

    return rc;
}

void model_clear(model &model)
{
    model_nodes_clear(model.nodes);
    model_edges_clear(model.edges);

    model_init_empty();
}

ERR_MODEL_PROXY model_move(model &model, const model_move_data_t &move_data)
{
    if (model_is_empty(model))
        return ERR_MODEL_IS_EMPTY;

    point_3d_move(model.center, move_data.deltas);

    return ERR_MODEL_OKAY;
}

ERR_MODEL_PROXY model_scale(model &model, const model_scale_data_t &scale_data)
{
    if (model_is_empty(model))
        return ERR_MODEL_IS_EMPTY;

    model_nodes_scale(model.nodes, scale_data);

    return ERR_MODEL_OKAY;
}

ERR_MODEL_PROXY model_rotate(model &model, const model_rotate_data_t &rotate_data)
{
    if (model_is_empty(model))
        return ERR_MODEL_IS_EMPTY;

    model_nodes_rotate(model.nodes, rotate_data);

    return ERR_MODEL_OKAY;
}

ERR_MODEL_PROXY model_draw(const model &model, const model_draw_data_t &draw_data)
{
    if (model_is_empty(model))
        return ERR_MODEL_IS_EMPTY;

    point_3D center = model.center;
    const model_nodes &nodes = model.nodes;
    const model_edges &edges = model.edges;

    for (std::size_t i = 0; i < edges.len; ++i)
    {
        size_t p1_i = model_edge_get_first_i(edges.data[i]);
        size_t p2_i = model_edge_get_second_i(edges.data[i]);

        struct point_2D point_1 = model_node_to_point_2d(nodes.data[p1_i],
                                                         center);
        struct point_2D point_2 = model_node_to_point_2d(nodes.data[p2_i],
                                                         center);

        model_draw_line(draw_data.canvas, point_1, point_2);
    }

    return ERR_MODEL_OKAY;
}
