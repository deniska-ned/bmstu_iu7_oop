#ifndef F_LIST_ITER_BASE_H
#define F_LIST_ITER_BASE_H

#include "f_list_node.hpp"

#include <iterator>

template <typename T>
class f_list_iter_base:
    public std::iterator<std::forward_iterator_tag, f_list_node<T>>
{
public:
    // Member methods

    f_list_iter_base() = delete;
    f_list_iter_base(const f_list_iter_base<T> & other) noexcept;
    explicit f_list_iter_base(
            std::shared_ptr<f_list_node<T>> node_ptr) noexcept;

    f_list_iter_base(f_list_iter_base<T> && other) noexcept;

    f_list_iter_base<T> & operator=(
            const f_list_iter_base<T> & other) noexcept;
    f_list_iter_base<T> & operator=(f_list_iter_base<T> && other) noexcept;

    virtual ~f_list_iter_base() = default;


    // Operations

    void swap(f_list_iter_base<T> & other) noexcept;


    // Overloaded operator

    bool operator==(const f_list_iter_base<T> & other) const noexcept;
    bool operator!=(const f_list_iter_base<T> & other) const noexcept;
    virtual const T & operator*() const = 0;
    virtual const T * operator->() const = 0;


    // Cast operators

    explicit operator bool() const noexcept;



protected:
    std::weak_ptr<f_list_node<T>> _node_ptr = std::weak_ptr<f_list_node<T>>();

    std::shared_ptr<f_list_node<T>> _get_node_ptr() const noexcept;

    void _inc();
};

#endif // F_LIST_ITER_BASE_H
