#ifndef F_LIST_NODE_HPP
#define F_LIST_NODE_HPP

#include "f_list_node.h"



//// public


// Member methods

template <typename T>
f_list_node<T>::f_list_node(T & data)
    : _data(data)
{}

template <typename T>
f_list_node<T>::f_list_node(const f_list_node<T> & other)
{
    this->_data = other._data;
    this->_next_ptr = other._next_ptr;
}

template <typename T>
f_list_node<T>::f_list_node(f_list_node<T> && other) noexcept
{
    if (this != &other)
    {
        swap(other);
    }
}

template <typename T>
f_list_node<T> & f_list_node<T>::operator=(const f_list_node<T> & other)
{
    if (this != &other)
    {
        f_list_node<T>(other).swap(*this);
    }

    return *this;
}

template <typename T>
f_list_node<T> & f_list_node<T>::operator=(f_list_node<T> && other) noexcept
{
    if (this != &other)
    {
        swap(other);
    }

    return *this;
}


// Operations

template <typename T>
void f_list_node<T>::swap(f_list_node<T> & other) noexcept
{
    std::swap(this->_data, other._data);
    std::swap(this->_next_ptr, other._next_ptr);
}


// Getters

template<typename T>
T &f_list_node<T>::get_data()
{
    return _data;
}

template<typename T>
const T &f_list_node<T>::get_data() const
{
    return _data;
}

template<typename T>
std::shared_ptr<f_list_node<T>> f_list_node<T>::get_next_ptr() const {
    return std::shared_ptr<f_list_node<T>>(_next_ptr);
}


// Setters

template<typename T>
void f_list_node<T>::set_data(const T & data)
{
    _data = data;
}

template <typename T>
void f_list_node<T>::set_next(std::shared_ptr<f_list_node<T>> next_ptr)
{
    _next_ptr = next_ptr;
}


#endif // F_LIST_NODE_HPP
