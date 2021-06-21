#ifndef F_LIST_ITER_BASE_HPP
#define F_LIST_ITER_BASE_HPP

#include "f_list_iter_base.h"

#include "f_list_error.hpp"


//// public


// Member methods

template <typename T>
f_list_iter_base<T>::f_list_iter_base(
        const f_list_iter_base<T> & other) noexcept
{
    this->_node_ptr = other._node_ptr;
}

template <typename T>
f_list_iter_base<T>::f_list_iter_base(
        std::shared_ptr<f_list_node<T>> node_ptr) noexcept
    : _node_ptr(node_ptr)
{}

template <typename T>
f_list_iter_base<T>::f_list_iter_base(f_list_iter_base<T> && other) noexcept
{
    swap(other);
}

template <typename T>
f_list_iter_base<T> & f_list_iter_base<T>::operator=(
        const f_list_iter_base<T> & other) noexcept
{
    if (this != &other)
    {
        f_list_iter_base<T>(other).swap(*this);
    }

    return *this;
}

template <typename T>
f_list_iter_base<T> & f_list_iter_base<T>::operator=(
        f_list_iter_base<T> && other) noexcept
{
    if (this != &other)
    {
        swap(other);
    }

    return *this;
}


// Operations

template <typename T>
void f_list_iter_base<T>::swap(f_list_iter_base<T> & other) noexcept
{
    std::swap(this->_node_ptr, other._node_ptr);
}


// Overloaded operator

template <typename T>
bool f_list_iter_base<T>::operator==(
        const f_list_iter_base<T> & other) const noexcept
{
    return this->_node_ptr.lock() == other._node_ptr.lock();
}

template <typename T>
bool f_list_iter_base<T>::operator!=(
        const f_list_iter_base<T> & other) const noexcept
{
    return !(*this == other);
}


// Cast operators

template <typename T>
f_list_iter_base<T>::operator bool() const noexcept
{
    return !_node_ptr.expired();
}



//// protected

template <typename T>
std::shared_ptr<f_list_node<T>> f_list_iter_base<T>::_get_node_ptr()
        const noexcept
{
    return _node_ptr.lock();
}

template <typename T>
void f_list_iter_base<T>::_inc()
{
    if (!*this)
    {
        throw f_list_error_iter_inc_impossible(__FILE__, typeid(*this).name(),
                                               __FUNCTION__, __LINE__);
    }

    _node_ptr = _node_ptr.lock()->get_next_ptr();
}

#endif // F_LIST_ITER_BASE_HPP
