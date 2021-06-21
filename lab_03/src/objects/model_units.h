#ifndef DETAILS_HPP
#define DETAILS_HPP

#include <memory>
#include <vector>

#include "objects/point.h"
#include "objects/edge.h"

class model_units
{
public:
    model_units() = default;
    ~model_units() = default;

    void add_point(point pt);
    void add_edge(edge ed);

    void reform(std::shared_ptr<Matrix<double>> reform_mtr);

    std::vector<point> get_points();
    std::vector<edge> get_edges();

private:
    std::vector<point> points;
    std::vector<edge> edges;
};

#endif // DETAILS_HPP
