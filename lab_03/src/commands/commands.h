#ifndef COMMANDS_HPP
#define COMMANDS_HPP


#include "base_classes/base_command.h"
#include "drawing/drawer.h"


class load_model : public base_command
{
public:
    explicit load_model(std::string & name): name(name) {};
    void execute() override;

private:
    std::string name;
};


class load_camera : public base_command
{
public:
    explicit load_camera(std::string & name) : name(name) {}
    void execute() override;

private:
    std::string name;
};


class load_scene : public base_command
{
public:
    explicit load_scene(std::string & name) : name(name) {}
    void execute() override;

private:
    std::string name;
};


class draw_scene : public base_command
{
public:
    explicit draw_scene(std::shared_ptr<base_drawer> drawer)
            : drawer(std::move(drawer)) {};
    void execute() override;

private:
    std::shared_ptr<base_drawer> drawer;
};


class reform_model : public base_command
{
public:
    explicit reform_model(size_t index, point & shift,
                          point & scale, point & rotate)
            : index(index), shift(shift), scale(scale), rotate(rotate) {};
    void execute() override;

private:
    size_t index;
    point shift;
    point scale;
    point rotate;
};


class reform_camera : public base_command
{
public:
    explicit reform_camera(size_t index, point & shift, point & rotate)
            : index(index), shift(shift), rotate(rotate) {};
    void execute() override;

private:
    size_t index;
    point shift;
    point rotate;
};


class remove_model : public base_command
{
public:
    explicit remove_model(size_t index) : index(index) {};
    void execute() override;

private:
    size_t index;
};


class remove_camera : public base_command
{
public:
    explicit remove_camera(size_t index) : index(index) {};
    void execute() override;

private:
    size_t index;
};


class set_camera : public base_command
{
public:
    explicit set_camera(size_t index) : index(index) {};
    void execute() override;

private:
    size_t index;
};

#endif // COMMANDS_HPP
