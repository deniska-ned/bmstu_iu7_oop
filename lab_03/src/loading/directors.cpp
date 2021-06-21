#include "directors.h"

#include "errors/errors.hpp"
#include "loading/loader_solution.h"


void base_director::set_filepath(std::string & filepath)
{
    _filepath = filepath;
}

model_director::model_director()
{
    _loader_ptr = loader_solution().get_creator()->get_loader();
}

void model_director::set_builder(
        std::shared_ptr<base_builder> builder_ptr)
{
    _builder_ptr = std::dynamic_pointer_cast<base_model_builder>(
            builder_ptr);

    if (nullptr == _builder_ptr)
    {
        std::string err_mess("Some message");
        throw incorrect_builder_cast_error(err_mess);
    }
}

void model_director::make()
{
    _loader_ptr->open(_filepath);

    size_t points_size = _loader_ptr->get_num();
    std::vector<point> points(points_size);

    for (point & p: points)
    {
        int x = _loader_ptr->get_num();
        int y = _loader_ptr->get_num();
        int z = _loader_ptr->get_num();

        p = point(x, y, z);
    }

    size_t edges_size = _loader_ptr->get_num();
    std::vector<edge> edges(edges_size);

    for (edge & e: edges)
    {
        int first_p_i = _loader_ptr->get_num();
        int second_p_i = _loader_ptr->get_num();

        e = edge(first_p_i, second_p_i);
    }

    _loader_ptr->close();

    _builder_ptr->reset();
    _builder_ptr->build_points(points);
    _builder_ptr->build_edges(edges);
}

camera_director::camera_director()
{
    _loader_ptr = loader_solution().get_creator()->get_loader();
}

void camera_director::set_builder(
        std::shared_ptr<base_builder> builder_ptr)
{
    _builder_ptr = std::dynamic_pointer_cast<base_camera_builder>(
            builder_ptr);

    if (nullptr == _builder_ptr)
    {
        std::string err_mess("Some message");
        throw incorrect_builder_cast_error(err_mess);
    }
}

void camera_director::make()
{
    _loader_ptr->open(_filepath);

    int cam_pos_x = _loader_ptr->get_num();
    int cam_pos_y = _loader_ptr->get_num();
    int cam_pos_z = _loader_ptr->get_num();

    int cam_angle_x = _loader_ptr->get_num();
    int cam_angle_y = _loader_ptr->get_num();
    int cam_angle_z = _loader_ptr->get_num();

    _loader_ptr->close();

    _builder_ptr->reset();
    _builder_ptr->build_position(cam_pos_x, cam_pos_y, cam_pos_z);
    _builder_ptr->build_angles(cam_angle_x, cam_angle_y, cam_angle_z);
}
