#include "loading/builders.h"
#include "objects/camera.h"


void model_builder::reset()
{
    _details = model_units();
}

void model_builder::build_points(std::vector<point> points)
{
    for (auto & point : points)
        _details.add_point(point);
}

void model_builder::build_edges(std::vector<edge> edges)
{
    for (auto & edge: edges)
        _details.add_edge(edge);
}

std::shared_ptr<object> model_builder::get_result()
{
    std::shared_ptr<model> modell;
    modell = std::make_shared<model>(_details);
    return modell;
}

void camera_builder::reset()
{
    _position = point();
    _angles = point();
}

void camera_builder::build_position(int x, int y, int z)
{
    _position = point(x, y, z);
}

void camera_builder::build_angles(int x, int y, int z)
{
    _angles = point(x, y, z);
}

std::shared_ptr<object> camera_builder::get_result()
{
    return std::make_shared<camera>(_position, _angles);
}
