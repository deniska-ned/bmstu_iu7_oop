#include "commands/facade.h"


void facade::execute_command(std::shared_ptr<base_command> command)
{
    command->execute();
}
