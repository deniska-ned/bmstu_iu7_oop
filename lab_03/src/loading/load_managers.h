#ifndef LAB_03_LOAD_MANAGERS_H
#define LAB_03_LOAD_MANAGERS_H

#include <memory>
#include "loading/directors.h"

#include "base_classes/base_manager.h"


class load_manager: base_manager
{
public:
    std::shared_ptr<object> load(std::shared_ptr<base_director> director,
                                 std::shared_ptr<base_builder> builder,
                                 std::string & srcpath);
};


class my_load_manager_creator
{
public:
    std::shared_ptr<load_manager> get_manager();

private:
    void _create_manager();

    std::shared_ptr<load_manager> _manager;
};


#endif //LAB_03_LOAD_MANAGERS_H
