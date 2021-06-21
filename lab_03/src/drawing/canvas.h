#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QGraphicsScene>
#include <utility>

#include "objects/point.h"


class base_canvas
{
public:
    virtual void draw_line(const point & p1, const point & p2) = 0;
    virtual void clear() = 0;
};


class qt_canvas : public base_canvas
{
public:
    explicit qt_canvas(std::shared_ptr<QGraphicsScene> scene_ptr)
            : _scene_ptr(std::move(scene_ptr)) {}
    void draw_line(const point & p1, const point & p2) override;
    void clear() override;

private:
    std::shared_ptr<QGraphicsScene> _scene_ptr;
};

#endif // CANVAS_HPP
