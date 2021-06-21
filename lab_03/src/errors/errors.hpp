#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <exception>
#include <string>


class base_error : public std::exception
{
protected:
    std::string er_msg;

public:
    explicit base_error(const std::string & er_msg) : er_msg(er_msg) {}

    const char *what() const noexcept override
    {
        return "Base error";
    }

    const std::string &get_info() const noexcept
    {
        return er_msg;
    }
};


class file_error : public base_error
{
public:
    explicit file_error(const std::string & er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "File error";
    }
};


class builder_error : public base_error
{
public:
    explicit builder_error(const std::string & er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "Builder error";
    }
};


class range_error : public base_error
{
public:
    explicit range_error(const std::string & er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "Range error";
    }
};


class memory_error : public base_error
{
public:
    explicit memory_error(const std::string & er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "Memory error";
    }
};


class no_director_error : public base_error
{
public:
    explicit no_director_error(std::string & er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "There is no director set";
    }
};


class no_camera_error : public base_error
{
public:
    explicit no_camera_error(std::string & er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "There is no camera set";
    }
};


class config_error : public base_error
{
public:
    explicit config_error(std::string & er_msg) : base_error(er_msg) {}

    const char *what() const noexcept override
    {
        return "Error in registration process";
    }
};


class incorrect_builder_cast_error: public base_error
{
public:
    explicit incorrect_builder_cast_error(std::string & message)
            : base_error(message) {}

    const char *what() const noexcept override
    {
        return "Incorrect dynamic cast of builder";
    }
};


class loader_solution_it_end_error: public base_error
{
public:
    explicit loader_solution_it_end_error(std::string & message)
            : base_error(message) {}

    const char *what() const noexcept override
    {
        return "Incorrect loader solution conf file";
    }
};


class drawer_solution_it_end_error: public base_error
{
public:
    explicit drawer_solution_it_end_error(std::string & message)
            : base_error(message) {}

    const char *what() const noexcept override
    {
        return "Incorrect drawer solution conf file";
    }
};

#endif // ERRORS_HPP
