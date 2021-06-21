#include "drawing/draw_manager.h"

#include <utility>
#include "errors/errors.hpp"
#include "reforming/transform_matrix.h"


std::shared_ptr<draw_manager> draw_manager_creator::get_manager()
{
    if (nullptr == _manager)
        create_manager();

    return _manager;
}

void draw_manager_creator::create_manager()
{
    static auto manager = std::make_shared<draw_manager>();
    this->_manager = manager;
}

void draw_manager::set_drawer(std::shared_ptr<base_drawer> drawer)
{
    _drawer = std::move(drawer);
}

void draw_manager::set_camera(std::shared_ptr<camera> camera)
{
    _camera = std::move(camera);
}

void draw_manager::draw(std::shared_ptr<scene> scene)
{
    _drawer->clear_scene();
    scene->get_models()->accept(std::make_shared<draw_visitor>(_camera, _drawer));
}
