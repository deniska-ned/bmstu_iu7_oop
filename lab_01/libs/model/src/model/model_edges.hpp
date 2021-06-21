#ifndef LAB_01_MODEL_EDGES_HPP
#define LAB_01_MODEL_EDGES_HPP

#include <cstdio>
#include <cstddef>

#include "model_edge.hpp"

struct model_edges
{
    struct model_edge *data;
    int len;
};

enum ERR_MODEL_EDGES
{
    ERR_MODEL_EDGES_OKAY,
    ERR_MODEL_EDGES_FILE_INCOR,
    ERR_MODEL_EDGES_ALLOC_FAILED,
    ERR_MODEL_EDGES_FILE_NULL
};

model_edges model_edges_empty();

bool model_edges_is_empty(const model_edges &edges);

ERR_MODEL_EDGES model_edges_load(model_edges &edges, FILE *f);

ERR_MODEL_EDGES
model_edges_fscan(model_edges &edges, size_t edges_count, FILE *f);

void model_edges_clear(model_edges &edges);

ERR_MODEL_EDGES model_edges_alloc(model_edges &edges);

#endif //LAB_01_MODEL_EDGES_HPP
