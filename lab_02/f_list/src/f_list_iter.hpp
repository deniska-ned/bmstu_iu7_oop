#ifndef F_LIST_ITER_HPP
#define F_LIST_ITER_HPP

#include "f_list_iter.h"

#include <iostream>

#include "f_list_error.hpp"



//// public


// Overloaded operators

template <typename T>
f_list_iter<T> &f_list_iter<T>::operator++() {
    this->_inc();

    return *this;
}

template <typename T>
f_list_iter<T> f_list_iter<T>::operator++(int) {
    f_list_iter<T> copy(*this);
    ++*this;

    return copy;
}

template <typename T>
T & f_list_iter<T>::operator*()
{
    if (this->_node_ptr.expired())
    {
        throw f_list_error_iter_expired(__FILE__, typeid(*this).name(),
                                        __FUNCTION__, __LINE__);
    }

    return this->_node_ptr.lock()->get_data();
}

template <typename T>
T * f_list_iter<T>::operator->()
{
    if (this->_node_ptr.expired())
    {
        throw f_list_error_iter_expired(__FILE__, typeid(*this).name(),
                                        __FUNCTION__, __LINE__);
    }

    return &(this->_node_ptr.lock()->get_data());
}

template <typename T>
const T & f_list_iter<T>::operator*() const
{
    if (this->_node_ptr.expired())
    {
        throw f_list_error_iter_expired(__FILE__, typeid(*this).name(),
                                        __FUNCTION__, __LINE__);
    }

    return this->_node_ptr.lock()->get_data();
}

template <typename T>
const T * f_list_iter<T>::operator->() const
{
    if (this->_node_ptr.expired())
    {
        throw f_list_error_iter_expired(__FILE__, typeid(*this).name(),
                                        __FUNCTION__, __LINE__);
    }

    return &(this->_node_ptr.lock()->get_data());
}


// Cast operators

template <typename T>
f_list_iter<T>::operator f_list_iter_const<T>() const noexcept
{
    f_list_iter_const<T> const_it(this->_node_ptr.lock());

    return const_it;
}

#endif // F_LIST_ITER_HPP
