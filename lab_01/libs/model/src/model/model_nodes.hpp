#ifndef LAB_01_MODEL_NODE_HPP
#define LAB_01_MODEL_NODE_HPP

#include <cstdio>
#include "points/point_2d.hpp"

#include "model_request_data_types.hpp"
#include "points/point_3d.hpp"

struct model_nodes
{
    struct point_3D *data;
    int len;
};

enum ERR_MODEL_NODES
{
    ERR_MODEL_NODES_OKAY,
    ERR_MODEL_NODES_FILE_INCOR,
    ERR_MODEL_NODES_ALLOC_FAILED,
    ERR_MODEL_NODES_IS_EMPTY,
    ERR_MODEL_NODES_FILE_NULL
};

model_nodes model_nodes_empty();

bool model_nodes_is_empty(const model_nodes &nodes);

ERR_MODEL_NODES model_nodes_load(model_nodes &nodes, FILE *f);

ERR_MODEL_NODES
model_nodes_fscan(model_nodes &nodes, int nodes_count, FILE *f);

void model_nodes_clear(model_nodes &nodes);

ERR_MODEL_NODES model_nodes_scale(model_nodes &nodes,
                                  const model_scale_data_t &scale_data);

ERR_MODEL_NODES model_nodes_rotate(model_nodes &nodes,
                                   const model_rotate_data_t &rotate_data);

ERR_MODEL_NODES model_nodes_alloc(model_nodes &nodes);

point_2D model_node_to_point_2d(const point_3D & point,
                                const point_3D & center);

#endif //LAB_01_MODEL_NODE_HPP
