#include "commands/commands.h"

#include "drawing/draw_manager.h"
#include "loading/load_managers.h"
#include "reforming/transform_matrix.h"
#include "reforming/reform_manager.h"
#include "objects/point.h"
#include "scene/scene_manager.h"


void load_model::execute()
{
    if (!scene_manager_creator().get_manager()->is_camera_exist())
    {
        std::string message = "There is no camera";
        throw no_camera_error(message);
    }

    auto load_manager_ptr = my_load_manager_creator().get_manager();
    auto director_ptr = std::make_shared<model_director>();
    auto builder_ptr = std::make_shared<model_builder>();

    std::shared_ptr<object> model = load_manager_ptr->load(
            director_ptr, builder_ptr, name);

    scene_manager_creator().get_manager()->get_scene()->add_model(model);
}


void load_camera::execute()
{
    auto load_manager_ptr = my_load_manager_creator().get_manager();
    auto director_ptr = std::make_shared<camera_director>();
    auto builder_ptr = std::make_shared<camera_builder>();

    std::shared_ptr<object> camera = load_manager_ptr->load(
            director_ptr, builder_ptr, name);

    scene_manager_creator().get_manager()->get_scene()->add_camera(camera);
}


void load_scene::execute()
{
    // TODO: code it like load model
}


void draw_scene::execute()
{
    if (!scene_manager_creator().get_manager()->is_camera_exist())
    {
        std::string message = "There is no camera";
        throw no_camera_error(message);
    }

    auto camera_ptr = scene_manager_creator().get_manager()->get_camera();
    auto scene_ptr = scene_manager_creator().get_manager()->get_scene();

    draw_manager_creator().get_manager()->set_camera(camera_ptr);
    draw_manager_creator().get_manager()->set_drawer(drawer);
    draw_manager_creator().get_manager()->draw(scene_ptr);
}


void reform_model::execute()
{
    auto scene = scene_manager_creator().get_manager()->get_scene();

    auto models_it = scene->get_models()->begin();
    std::advance(models_it, index);
    auto model = *models_it;

    reform_manager_creator().get_manager()->shift_model(model, shift);
    reform_manager_creator().get_manager()->scale_model(model, scale);
    reform_manager_creator().get_manager()->rotate_model(model, rotate);
}


void reform_camera::execute()
{
    auto scene_ptr = scene_manager_creator().get_manager()->get_scene();

    auto cameras_it = scene_ptr->get_models()->begin();
    std::advance(cameras_it, index);
    auto camera = *cameras_it;

    reform_manager_creator().get_manager()->shift_model(camera, shift);

    std::shared_ptr<Matrix<double>> reform_mtr(
            std::make_shared<MoveMatrix>(rotate));
    scene_manager_creator().get_manager()->get_camera()->rotate(reform_mtr);
}


void remove_model::execute()
{
    scene_manager_creator().get_manager()->get_scene()->remove_model(index);
}


void remove_camera::execute()
{
    scene_manager_creator().get_manager()->get_scene()->remove_camera(index);
}


void set_camera::execute()
{
    scene_manager_creator().get_manager()->set_camera(index);
}
