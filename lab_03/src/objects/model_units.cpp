#include "objects/model_units.h"


void model_units::add_point(point pt)
{
    points.push_back(pt);
}

void model_units::add_edge(edge ed)
{
    edges.push_back(ed);
}

std::vector<point> model_units::get_points()
{
    return points;
}

std::vector<edge> model_units::get_edges()
{
    return edges;
}

void model_units::reform(std::shared_ptr<Matrix<double>> reform_mtr)
{
    for (auto &point : points)
    {
        point.reform(reform_mtr);
    }
}
