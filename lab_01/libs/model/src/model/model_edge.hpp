#ifndef LAB_01_MODEL_EDGE_HPP
#define LAB_01_MODEL_EDGE_HPP

#include <cstdio>
#include <cstddef>

struct model_edge
{
    size_t first;
    size_t second;
};

enum ERR_MODEL_EDGE
{
    ERR_MODEL_EDGE_OKAY,
    ERR_MODEL_EDGE_INCOR_FILE,
    ERR_MODEL_EDGE_FILE_NULL
};

ERR_MODEL_EDGE model_edge_fscan(model_edge &edge, FILE *f);

size_t model_edge_get_first_i(const model_edge & edge);

size_t model_edge_get_second_i(const model_edge & edge);

#endif //LAB_01_MODEL_EDGE_HPP
