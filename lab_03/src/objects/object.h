#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <memory>
#include <vector>

#include "drawing/draw_visitor.h"
#include "objects/point.h"
#include "base_classes/base_visitor.h"


class object
{
public:
    object() = default;
    ~object() = default;

    virtual bool add(std::shared_ptr<object> obj) { return false; }
    virtual bool remove(long index) { return false; }

    virtual void accept(std::shared_ptr<base_visitor> _visitor) = 0;
    virtual bool is_composite() = 0;
    virtual bool is_visible() = 0;
    virtual void reform(std::shared_ptr<Matrix<double>> reform_mtr) = 0;
};

class visible_object : public object
{
public:
    visible_object() = default;
    ~visible_object() = default;

    bool is_visible() override { return true; }
};

class invisible_object : public object
{
public:
    invisible_object() = default;
    ~invisible_object() = default;

    bool is_visible() override { return false; }
};

#endif // OBJECT_HPP
