#ifndef F_LIST_ERROR_HPP
#define F_LIST_ERROR_HPP

#include <exception>
#include <chrono>
#include <string>

class f_list_error_base: public std::exception
{
public:
    f_list_error_base(
            const std::string & file_name,
            const std::string & class_name,
            const std::string & method_name,
            const uint line_number,
            const std::string & message = "No error message")
            : _time(std::chrono::system_clock::now()),
              _file_name(file_name),
              _class_name(class_name),
              _method_name(method_name),
              _line_number(line_number),
              _message(message)
    {}

    const char * what() const noexcept
    {
        return _message.c_str();
    }

    const std::string log_mess(std::string sep = " | ") const
    {
        time_t tt = std::chrono::system_clock::to_time_t(_time);
        std::string time_str(std::ctime(&tt));
        return time_str + sep
               + _file_name + sep
               + _class_name + sep
               + _method_name + sep
               + std::to_string(_line_number) + sep
               + typeid(*this).name() + ": "
               + _message;
    }

private:
    std::chrono::system_clock::time_point _time;
    std::string _file_name;
    std::string _class_name;
    std::string _method_name;
    uint _line_number;
    std::string _message;
};

class f_list_error_bad_alloc: public f_list_error_base
{
public:
    f_list_error_bad_alloc(
            const std::string & file_name,
            const std::string & class_name,
            const std::string & method_name,
            const uint line_number,
            const std::string & message = "No error message")
        : f_list_error_base(file_name, class_name, method_name, line_number,
                            "bad alloc: " + message)
        {};
};

class f_list_error_iter_inc_impossible: public f_list_error_base
{
public:
    f_list_error_iter_inc_impossible(
            const std::string & file_name,
            const std::string & class_name,
            const std::string & method_name,
            const uint line_number,
            const std::string & message = "No error message")
        : f_list_error_base(file_name, class_name, method_name, line_number,
                            "iter inc impossible: " + message)
        {};
};

class f_list_error_iter_expired: public f_list_error_base
{
public:
    f_list_error_iter_expired(
            const std::string & file_name,
            const std::string & class_name,
            const std::string & method_name,
            const uint line_number,
            const std::string & message = "No error message")
        : f_list_error_base(file_name, class_name, method_name, line_number,
                            "iter expired: " + message)
        {};
};

#endif // F_LIST_ERROR_HPP
