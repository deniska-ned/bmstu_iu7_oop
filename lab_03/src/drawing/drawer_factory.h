#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

#include <memory>

#include "drawing/drawer.h"


class base_drawer_creator
{
public:
    virtual std::shared_ptr<base_drawer> create() const = 0;
};


class qt_factory : public base_drawer_creator
{
public:
    std::shared_ptr<base_drawer> create() const override;
};

#endif // ABSTRACT_FACTORY_HPP
