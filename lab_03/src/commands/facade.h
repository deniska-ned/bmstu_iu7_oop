#ifndef FACADE_HPP
#define FACADE_HPP

#include "commands/commands.h"


class facade
{
public:
    void execute_command(std::shared_ptr<base_command> command);
};

#endif // FACADE_HPP
