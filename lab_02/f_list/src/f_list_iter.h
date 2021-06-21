#ifndef F_LIST_ITER_H
#define F_LIST_ITER_H

#include "f_list_iter_base.hpp"
#include "f_list_iter_const.hpp"

template <typename T>
class f_list_iter: public f_list_iter_base<T>
{
public:
    // Member methods

    using f_list_iter_base<T>::f_list_iter_base;


    // Overloaded operators

    f_list_iter<T> & operator++();
    f_list_iter<T> operator++(int);
    T & operator*();
    T * operator->();
    const T & operator*() const override;
    const T * operator->() const override;


    // Cast operators

    operator f_list_iter_const<T>() const noexcept;
};


#endif // F_LIST_ITER_H
