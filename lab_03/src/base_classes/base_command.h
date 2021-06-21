#ifndef LAB_03_BASE_COMMAND_H
#define LAB_03_BASE_COMMAND_H


class base_command
{
public:
    virtual ~base_command() = default;

    virtual void execute() = 0;
};

#endif //LAB_03_BASE_COMMAND_H
