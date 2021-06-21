#ifndef DRAW_MANAGER_HPP
#define DRAW_MANAGER_HPP

#include <memory>

#include "base_classes/base_manager.h"
#include "drawing/draw_visitor.h"
#include "scene/scene.h"


class draw_manager : public base_manager
{
public:
    draw_manager() = default;

    void set_drawer(std::shared_ptr<base_drawer> drawer);
    void set_camera(std::shared_ptr<camera> camera);

    void draw(std::shared_ptr<scene> scene);

private:
    std::shared_ptr<base_drawer> _drawer;
    std::shared_ptr<camera> _camera;
};


class draw_manager_creator
{
public:
    std::shared_ptr<draw_manager> get_manager();

private:
    void create_manager();

    std::shared_ptr<draw_manager> _manager;
};

#endif // DRAW_MANAGER_HPP
