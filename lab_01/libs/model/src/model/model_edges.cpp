#include "model_edges.hpp"

#include <cstdlib>
#include <cinttypes>

ERR_MODEL_EDGES err_conv_me2mes(const ERR_MODEL_EDGE rc_me)
{
    ERR_MODEL_EDGES rc_mes;

    switch (rc_me)
    {
        case ERR_MODEL_EDGE_OKAY:
            rc_mes = ERR_MODEL_EDGES_OKAY;
            break;
        case ERR_MODEL_EDGE_INCOR_FILE:
            rc_mes = ERR_MODEL_EDGES_FILE_INCOR;
            break;
        case ERR_MODEL_EDGE_FILE_NULL:
            rc_mes = ERR_MODEL_EDGES_FILE_NULL;
            break;
    }

    return rc_mes;
}

model_edges model_edges_empty()
{
    return { .data = nullptr, .len = 0 };
}

bool model_edges_is_empty(const model_edges &edges)
{
    return nullptr == edges.data || 0 == edges.len;
}

ERR_MODEL_EDGES model_edges_load(model_edges &edges, FILE *f)
{
    model_edges edges_tmp = model_edges_empty();

    if (1 != fscanf(f, "%d", &edges_tmp.len) || edges_tmp.len < 0)
        return ERR_MODEL_EDGES_FILE_INCOR;

    if (ERR_MODEL_EDGES_OKAY != model_edges_alloc(edges_tmp))
        return ERR_MODEL_EDGES_ALLOC_FAILED;

    if (ERR_MODEL_EDGES_OKAY != model_edges_fscan(edges_tmp, edges_tmp.len, f))
    {
        model_edges_clear(edges_tmp);
        return ERR_MODEL_EDGES_FILE_INCOR;
    }

    edges = edges_tmp;

    return ERR_MODEL_EDGES_OKAY;
}

ERR_MODEL_EDGES
model_edges_fscan(model_edges &edges, size_t edges_count, FILE *f)
{
    ERR_MODEL_EDGE rc_edge = ERR_MODEL_EDGE_OKAY;

    for (size_t i = 0; i < edges_count && ERR_MODEL_EDGE_OKAY == rc_edge; ++i)
        rc_edge = model_edge_fscan(edges.data[i], f);

    return err_conv_me2mes(rc_edge);
}

void model_edges_clear(model_edges &edges)
{
    free(edges.data);

    edges = model_edges_empty();
}

ERR_MODEL_EDGES model_edges_alloc(model_edges &edges)
{
    ERR_MODEL_EDGES rc = ERR_MODEL_EDGES_OKAY;

    model_edge *edges_mem = (model_edge *) malloc(
            sizeof(model_edge) * edges.len);

    if (nullptr != edges_mem)
        edges.data = edges_mem;
    else
        rc = ERR_MODEL_EDGES_ALLOC_FAILED;

    return rc;
}
