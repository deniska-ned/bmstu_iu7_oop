#ifndef LAB_01_QT_MODEL_PROXY_HPP
#define LAB_01_QT_MODEL_PROXY_HPP

#include "model_request_data_types.hpp"

#include "model_errors.hpp"

enum REQUEST_TYPE
{
    MRT_FILE_INIT,
    MRT_DESTROY,

    MRT_MOVE,
    MRT_SCALE,
    MRT_ROTATE,

    MRT_DRAW
};

struct model_request
{
    enum REQUEST_TYPE request_type;

    union
    {
        model_file_init_t file_data;
        model_move_data_t mov_data;
        model_scale_data_t sca_data;
        model_rotate_data_t rot_data;
        model_draw_data_t draw_data;
    };
};

ERR_MODEL_PROXY model_send_request(struct model_request request);

#endif //LAB_01_QT_MODEL_PROXY_HPP
