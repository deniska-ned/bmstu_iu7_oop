#include "model_edge.hpp"

ERR_MODEL_EDGE model_edge_fscan(model_edge &edge, FILE *f)
{
    if (nullptr == f)
    {
        return ERR_MODEL_EDGE_FILE_NULL;
    }

    long node_1, node_2;

    if (2 != fscanf(f, "%ld %ld", &node_1, &node_2))
    {
        return ERR_MODEL_EDGE_INCOR_FILE;
    }

    edge.first = node_1;
    edge.second = node_2;

    return ERR_MODEL_EDGE_OKAY;
}

size_t model_edge_get_first_i(const model_edge & edge)
{
    return edge.first;
}

size_t model_edge_get_second_i(const model_edge & edge)
{
    return edge.first;
}

