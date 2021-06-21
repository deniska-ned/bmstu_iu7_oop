#include "loader_solution.h"

#include <fstream>

#include "errors/errors.hpp"


void loader_solution::read_conf(std::string conffilename)
{
    std::string class_name;

    std::ifstream stream;
    stream.open(conffilename, std::ios::in);
    stream >> class_name;
    stream.close();

    auto res = _map.find(class_name);
    _selected = res;
}

bool loader_solution::registration(std::string class_name,
                                   std::shared_ptr<base_loader_creator> creator_ptr) {
    bool inserted = _map.insert(
            std::make_pair(class_name,creator_ptr)).second;
    return inserted;
}

std::shared_ptr<base_loader_creator> loader_solution::get_creator() {
    if (_map.end() == _selected)
    {
        std::string dummy("");
        throw loader_solution_it_end_error(dummy);
    }

    return _selected->second;
}

loader_solution::creator_map loader_solution::_map;
loader_solution::creator_map::iterator loader_solution::_selected = \
        loader_solution::_map.end();
