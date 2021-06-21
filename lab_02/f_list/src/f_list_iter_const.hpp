#ifndef F_LIST_ITER_CONST_HPP
#define F_LIST_ITER_CONST_HPP

#include "f_list_iter_const.h"



//// public


// Overloaded operators

template <typename T>
f_list_iter_const<T> &f_list_iter_const<T>::operator++() {
    this->_inc();

    return *this;
}

template <typename T>
f_list_iter_const<T> f_list_iter_const<T>::operator++(int) {
    f_list_iter_const<T> copy(*this);
    ++*this;

    return copy;
}

template <typename T>
const T & f_list_iter_const<T>::operator*() const
{
    if (this->_node_ptr.expired())
    {
        throw f_list_error_iter_expired(__FILE__, typeid(*this).name(),
                                        __FUNCTION__, __LINE__);
    }

    return this->_node_ptr.lock()->get_data();
}

template <typename T>
const T * f_list_iter_const<T>::operator->() const
{
    if (this->_node_ptr.expired())
    {
        throw f_list_error_iter_expired(__FILE__, typeid(*this).name(),
                                        __FUNCTION__, __LINE__);
    }

    return &(this->_node_ptr.lock()->get_data());
}

#endif // F_LIST_ITER_CONST_HPP
