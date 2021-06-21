#include "qt_model_drawer.hpp"

void model_draw_line(const model_draw_mediator_t drawer,
                     const point_2D point_1, const point_2D point_2)
{
    drawer.scene->addLine(point_1.x, point_1.y, point_2.x, point_2.y);
}
