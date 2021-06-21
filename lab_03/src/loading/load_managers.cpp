#include "objects/object.h"
#include "loading/load_managers.h"


std::shared_ptr<object>
load_manager::load(std::shared_ptr<base_director> director,
                      std::shared_ptr<base_builder> builder,
                      std::string &srcpath) {
    director->set_builder(builder);
    director->set_filepath(srcpath);
    director->make();
    return builder->get_result();
}

std::shared_ptr<load_manager> my_load_manager_creator::get_manager()
{
    if (nullptr == _manager)
        _create_manager();

    return _manager;
}

void my_load_manager_creator::_create_manager()
{
    _manager = std::make_shared<load_manager>();
}
