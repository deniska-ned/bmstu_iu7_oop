#ifndef LAB_03_DRAWER_SOLUTION_H
#define LAB_03_DRAWER_SOLUTION_H

#include <memory>
#include <string>
#include <unordered_map>

#include "drawing/drawer_factory.h"


class drawer_solution
{
public:
    bool registration(std::string class_name,
                      std::shared_ptr<base_drawer_creator> creator_ptr);
    void read_conf(std::string conffilename);
    std::shared_ptr<base_drawer_creator> get_creator();

    using creator_map = std::unordered_map<std::string,
            std::shared_ptr<base_drawer_creator>>;
private:

    static creator_map _map;
    static creator_map::iterator _selected;
};

#endif //LAB_03_DRAWER_SOLUTION_H
