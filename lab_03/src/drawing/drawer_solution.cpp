#include "drawing/drawer_solution.h"

#include <fstream>


bool drawer_solution::registration(std::string class_name,
        std::shared_ptr<base_drawer_creator> creator_ptr)
{
    bool inserted = _map.insert(
            std::make_pair(class_name, creator_ptr)).second;
    return inserted;
}

void drawer_solution::read_conf(std::string conffilename)
{
    std::string class_name;

    std::ifstream stream;
    stream.open(conffilename, std::ios::in);
    stream >> class_name;
    stream.close();

    auto res = _map.find(class_name);
    _selected = res;
}

std::shared_ptr<base_drawer_creator> drawer_solution::get_creator()
{
    if (_map.end() == _selected)
    {
        std::string dummy("");
        throw drawer_solution_it_end_error(dummy);
    }

    return _selected->second;
}

drawer_solution::creator_map drawer_solution::_map;
drawer_solution::creator_map::iterator drawer_solution::_selected = \
        drawer_solution::_map.end();
