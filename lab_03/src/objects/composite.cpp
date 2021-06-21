#include "objects/composite.h"

bool composite::add(std::shared_ptr<object> obj)
{
    objects.push_back(obj);
    return true;
}

bool composite::remove(long index)
{
    objects.erase(objects.begin() + index);
    return true;
}

std::vector<std::shared_ptr<object>>::iterator composite::begin()
{
    return objects.begin();
}

std::vector<std::shared_ptr<object>>::iterator composite::end()
{
    return objects.end();
}

std::vector<std::shared_ptr<object>>::const_iterator composite::cbegin() const
{
    return objects.cbegin();
}

std::vector<std::shared_ptr<object>>::const_iterator composite::cend() const
{
    return objects.cend();
}

void composite::accept(std::shared_ptr<base_visitor> visitor)
{
    for (const auto& obj : objects)
        obj->accept(visitor);
}

void composite::reform(std::shared_ptr<Matrix<double>> reform_mtr)
{
    for (const auto& obj : objects)
        obj->reform(reform_mtr);
}
