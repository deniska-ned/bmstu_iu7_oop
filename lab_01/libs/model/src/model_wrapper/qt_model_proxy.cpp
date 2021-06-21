#include "qt_model_proxy.hpp"

#include "model.hpp"

ERR_MODEL_PROXY model_send_request(struct model_request request)
{
    static struct model model = model_init_empty();

    ERR_MODEL_PROXY rc = ERR_MODEL_OKAY;

    switch (request.request_type)
    {
        case MRT_FILE_INIT:
            rc = model_file_load(model, request.file_data);
            break;
        case MRT_DESTROY:
            model_clear(model);
            break;
        case MRT_MOVE:
            rc = model_move(model, request.mov_data);
            break;
        case MRT_SCALE:
            rc = model_scale(model, request.sca_data);
            break;
        case MRT_ROTATE:
            rc = model_rotate(model, request.rot_data);
            break;
        case MRT_DRAW:
            rc = model_draw(model, request.draw_data);
            break;
        default:
            rc = ERR_MODEL_INCOR_REQUEST;
    }

    return rc;
}
