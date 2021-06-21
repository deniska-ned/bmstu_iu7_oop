#ifndef F_LIST_ITER_CONST_H
#define F_LIST_ITER_CONST_H

#include "f_list_iter_base.hpp"

template <typename T>
class f_list;

template <typename T>
class f_list_iter_const: public f_list_iter_base<T>
{
public:
    friend class f_list<T>;


    // Member methods

    using f_list_iter_base<T>::f_list_iter_base;


    // Overloaded operators

    f_list_iter_const<T> & operator++();
    f_list_iter_const<T> operator++(int);
    const T & operator*() const override;
    const T * operator->() const override;
};


#endif // F_LIST_ITER_CONST_H
