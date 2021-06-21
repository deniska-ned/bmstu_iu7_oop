#include "scene/scene.h"

scene::scene()
        :models(std::make_shared<composite>()),
         cameras(std::make_shared<composite>())
{}

void scene::add_model(std::shared_ptr<object> _model)
{
    models->add(_model);
}

void scene::remove_model(long index)
{
    models->remove(index);
}

void scene::add_camera(std::shared_ptr<object> _camera)
{
    cameras->add(_camera);
}

void scene::remove_camera(long index)
{
    cameras->remove(index);
}
