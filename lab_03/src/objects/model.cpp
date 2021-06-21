#include "model.h"

model::model()
    : _model_units(model_units())
{
}

model::model(model_units & _details)
    : _model_units(_details)
{
}

void model::accept(std::shared_ptr<base_visitor> _visitor)
{
    _visitor->visit(*this);
}

void model::reform(std::shared_ptr<Matrix<double>> reform_mtr)
{
    _model_units.reform(reform_mtr);
}
