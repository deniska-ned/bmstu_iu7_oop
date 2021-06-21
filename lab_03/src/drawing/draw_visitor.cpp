#include "draw_visitor.h"
#include "reforming/transform_matrix.h"
#include "objects/model.h"
#include "objects/camera.h"

draw_visitor::draw_visitor(std::shared_ptr<camera> _camera,
                           std::shared_ptr<base_drawer> _drawer)
    :_camera(_camera), _drawer(_drawer)
{
}

void draw_visitor::visit(model &_model)
{
    if (!_drawer)
    {
        std::string message = "Error while drawing model: no drawer";
        throw file_error(message);
    }
    if (!_camera)
    {
        std::string message = "Error while drawing model: no camera";
        throw file_error(message);
    }

    auto details = _model._model_units;
    auto points = details.get_points();
    auto edges = details.get_edges();

    for (auto &edge : edges)
    {
        _drawer->draw_line(get_projection(points[edge.get_first()]),
                          get_projection(points[edge.get_second()]));
    }
}

point draw_visitor::get_projection(point &_point)
{
    point projection(_point);
    point move(-_camera->get_position().get_x(), -_camera->get_position().get_y(), 0);
    std::shared_ptr<Matrix<double>> reform_mtr(std::make_shared<MoveMatrix>(_camera->get_position()));

    projection.reform(reform_mtr);

    point angles = _camera->get_angles().deg_to_rad();
    reform_mtr = std::make_shared<RotateOxMatrix>(-angles.get_x());
    projection.reform(reform_mtr);

    reform_mtr = std::make_shared<RotateOyMatrix>(-angles.get_y());
    projection.reform(reform_mtr);

    reform_mtr = std::make_shared<RotateOzMatrix>(-angles.get_z());
    projection.reform(reform_mtr);

    return projection;
}
