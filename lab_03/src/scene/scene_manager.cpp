#include "scene/scene_manager.h"
#include <memory>

std::shared_ptr<scene_manager> scene_manager_creator::get_manager()
{
    if (_manager == nullptr)
        create_manager();

    return _manager;
}

void scene_manager_creator::create_manager()
{
    static auto manager = std::make_shared<scene_manager>();
    this->_manager = manager;
}

scene_manager::scene_manager()
    :/*scene(std::make_shared<scene>()),*/ _camera(nullptr)
{
    _scene = std::make_shared<scene>();
}

std::shared_ptr<scene> scene_manager::get_scene()
{
    return _scene;
}

std::shared_ptr<camera> scene_manager::get_camera()
{
    return _camera;
}

void scene_manager::set_camera(long index)
{
    if (_scene->get_cameras()->begin() == _scene->get_cameras()->end())
    {
        _camera = nullptr;
        return;
    }
    auto it = _scene->get_cameras()->begin();
    std::advance(it, index);
    auto cameraa = *it;

    _camera = std::dynamic_pointer_cast<camera>(cameraa);
}
