#ifndef LAB_01_MODEL_REQUEST_DATA_TYPES_HPP
#define LAB_01_MODEL_REQUEST_DATA_TYPES_HPP

#include "model_draw_mediator.hpp"

#include "points/point_3d.hpp"

struct model_file_init_t
{
    char *filename;
};

struct model_move_data_t
{
    struct point_3D_diff deltas;
};

struct model_scale_data_t
{
    struct point_3D_diff coefficients;
};

struct model_rotate_data_t
{
    struct point_3D_diff angles;
};

struct model_draw_data_t
{
    struct model_draw_mediator_t canvas;
};

#endif //LAB_01_MODEL_REQUEST_DATA_TYPES_HPP
