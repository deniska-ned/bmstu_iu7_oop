#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "base_classes/base_visitor.h"
#include "drawing/drawer.h"


class draw_visitor: public base_visitor
{
public:
    draw_visitor(std::shared_ptr<camera> camera,
                 std::shared_ptr<base_drawer> drawer);
    ~draw_visitor() = default;

    void visit(model & model) override;
    void visit(camera & camera) override {};
    void visit(scene & scene) override {};
    void visit(composite & composite) override {};

private:
    point get_projection(point & point);
    std::shared_ptr<camera> _camera;
    std::shared_ptr<base_drawer> _drawer;
};

#endif // VISITOR_HPP
