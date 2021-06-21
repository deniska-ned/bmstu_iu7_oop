#ifndef MODEL_HPP
#define MODEL_HPP

#include "objects/object.h"
#include "objects/model_units.h"

class model : public visible_object
{
    friend class draw_visitor;
public:
    model();
    explicit model(model_units & _details);

    void accept(std::shared_ptr<base_visitor> _visitor) override;
    bool is_composite() override { return false; }
    void reform(std::shared_ptr<Matrix<double>> reform_mtr) override;

private:
    model_units _model_units;
};

#include "drawing/draw_visitor.h"

#endif // MODEL_HPP
