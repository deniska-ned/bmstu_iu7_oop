#include "drawing/drawer_factory.h"

std::shared_ptr<base_drawer> qt_factory::create() const
{
    return std::make_shared<qt_drawer>();
}
