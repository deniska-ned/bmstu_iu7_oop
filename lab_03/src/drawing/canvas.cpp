#include "drawing/canvas.h"

void qt_canvas::draw_line(const point & p1, const point & p2)
{
    _scene_ptr->addLine(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
}

void qt_canvas::clear()
{
    _scene_ptr->clear();
}
