#ifndef LAB_01_FIGURE_HPP
#define LAB_01_FIGURE_HPP

#include <utility>
#include <model_errors.hpp>

#include "model_request_data_types.hpp"
#include "points/point_3d.hpp"

#include "model_nodes.hpp"
#include "model_edges.hpp"

struct model
{
    struct point_3D center;

    struct model_nodes nodes;
    struct model_edges edges;
};

struct model model_init_empty();
bool model_is_empty(const model &model);
ERR_MODEL_PROXY
model_file_load(struct model &model, const model_file_init_t &file_data);
void model_clear(model &model);

ERR_MODEL_PROXY model_move(model &model, const model_move_data_t &move_data);
ERR_MODEL_PROXY model_scale(model &model, const model_scale_data_t &scale_data);
ERR_MODEL_PROXY model_rotate(model &model, const model_rotate_data_t &rotate_data);

ERR_MODEL_PROXY model_draw(const model &model, const model_draw_data_t &draw_data);

#endif //LAB_01_FIGURE_HPP
