#ifndef LAB_03_LOADER_CREATORS_H
#define LAB_03_LOADER_CREATORS_H

#include <memory>

#include "loading/loaders.h"


class base_loader_creator
{
public:
    virtual std::shared_ptr<base_loader> get_loader() = 0;
};


class file_loader_creator: public base_loader_creator
{
public:
    std::shared_ptr<base_loader> get_loader() override;
};

#endif //LAB_03_LOADER_CREATORS_H
