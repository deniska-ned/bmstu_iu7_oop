#ifndef OBJECT_CAMERA_HPP
#define OBJECT_CAMERA_HPP

#include "objects/object.h"
#include "drawing/draw_visitor.h"
#include "commands/commands.h"


class camera : public invisible_object
{
    friend class draw_visitor;
    friend class reform_camera;

public:
    camera();
    explicit camera(const point &pos, const point &angs);
    void reform(const std::shared_ptr<Matrix<double>> reform_mtr) override;
    bool is_composite() override { return false; }
    void accept(std::shared_ptr<base_visitor> _visitor) override;

private:
    point position;
    point angles;

    const point &get_position() const;
    const point &get_angles() const;
    void set_position(const point &position);
    void set_angles(const point &angles);
    void rotate(const std::shared_ptr<Matrix<double>> reform_mtr);
};

#endif
