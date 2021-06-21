#ifndef F_LIST_HPP
#define F_LIST_HPP

#include <utility>
#include <memory>

#include "f_list.h"

#include "forward_list"



//// public:


// Member methods

template <typename T>
f_list<T>::f_list(const f_list<T> & other)
{
    std::forward_list<int> list(10, 5);

    for (const T value: other)
        push_back(value);
}

template <typename T>
f_list<T>::f_list(size_t count)
{
    T some_value;
    for (size_t i = 0; i < count; ++i)
        push_back(some_value);
}

template<typename T>
f_list<T>::f_list(const T * arr, size_t arr_size)
{
    for (size_t el_num = arr_size; el_num > 0; --el_num)
        push_front(arr[el_num - 1]);
}

template <typename T>
f_list<T>::f_list(std::initializer_list<T> init)
{
    for (const T & value: init)
        push_back(value);
}

template<typename T>
template<class InputIt>
f_list<T>::f_list(InputIt first, InputIt last)
{
    for (InputIt it = first; it != last; ++it)
        push_back(*it);
}

template <typename T>
f_list<T>::f_list(f_list<T> && other) noexcept
{
    if (this != &other)
    {
        swap(other);
    }
}

template <typename T>
f_list<T> & f_list<T>::operator=(const f_list<T> & other)
{
    if (this != &other)
    {
        f_list<T>(other).swap(*this);
    }

    return *this;
}

template <typename T>
f_list<T> & f_list<T>::operator=(f_list<T> && other) noexcept
{
    if (this != &other)
    {
        swap(other);
    }

    return *this;
}

template<typename T>
f_list<T> &f_list<T>::operator=(std::initializer_list<T> init) {
    clear();

    for (const T & value: init)
        push_back(value);
}



// Iterators

template<typename T>
f_list_iter<T> f_list<T>::begin()
{
    return f_list_iter<T>(_head_ptr);
}

template<typename T>
f_list_iter<T> f_list<T>::end()
{
    return f_list_iter<T>(std::shared_ptr<f_list_node<T>>());
}

template<typename T>
f_list_iter_const<T> f_list<T>::begin() const
{
    return f_list_iter_const<T>(_head_ptr);
}

template<typename T>
f_list_iter_const<T> f_list<T>::end() const
{
    return f_list_iter_const<T>(std::shared_ptr<f_list_node<T>>());
}

template<typename T>
f_list_iter_const<T> f_list<T>::cbegin() const
{
    return f_list_iter_const<T>(_head_ptr);
}

template<typename T>
f_list_iter_const<T> f_list<T>::cend() const
{
    return f_list_iter_const<T>(std::shared_ptr<f_list_node<T>>());
}


// State

template <typename T>
size_t f_list<T>::size() const
{
    return _size;
}

template <typename T>
bool f_list<T>::is_empty() const
{
    return 0 == _size;
}

template<typename T>
bool f_list<T>::eq(const f_list<T> & other) const
{
    if (this->size() != other.size())
        return false;

    auto this_it = this->begin();
    auto other_it = other.begin();
    for (; this_it != this->end(); ++this_it, ++other_it)
        if (*this_it != *other_it)
            return false;

    return true;
}

template<typename T>
bool f_list<T>::ne(const f_list<T> & other) const
{
    return !this->eq(other);
}


// Modifiers

template <typename T>
void f_list<T>::push_front(const T & value)
{
    T value_copy = value;
    _push_front(std::move(value_copy));
}

template <typename T>
void f_list<T>::push_front(T && value)
{
    _push_front(std::move(value));
}

template <typename T>
void f_list<T>::push_front(const f_list<T> & other)
{
    f_list<T> other_copy(other);
    other_copy.splice(*this);
    swap(other_copy);
}

template <typename T>
void f_list<T>::push_back(const T & value)
{
    T value_copy = value;
    _push_back(std::move(value_copy));
}

template <typename T>
void f_list<T>::push_back(T && value)
{
    _push_back(std::move(value));
}

template <typename T>
void f_list<T>::push_back(const f_list<T> & other)
{
    f_list<T> other_copy(other);
    splice(other_copy);
}

template<typename T>
void f_list<T>::insert_after(f_list_iter_const<T> pos, const T& value)
{
    f_list<T> slice = {value};
    insert_after(pos, slice.begin(), slice.end());
}

template<typename T>
template <class InputIt>
void f_list<T>::insert_after(f_list_iter_const<T> pos,
                             InputIt first, InputIt last)
{
    // TODO: implement checks for iter

    f_list<T> slice(first, last);

    if (!slice.is_empty())
    {
        f_list_iter_const<T> pos_next = pos;
        ++pos_next;

        auto slice_tail = slice._get_tail_ptr();
        slice_tail->set_next(pos_next._get_node_ptr());
        pos._get_node_ptr()->set_next(slice._head_ptr);

        _size += slice.size();
    }
}

template<typename T>
void f_list<T>::insert_after(f_list_iter_const<T> pos,
                             std::initializer_list<T> ilist)
{
    insert_after(pos, ilist.begin(), ilist.end());
}

template<typename T>
void f_list<T>::erase_after(const f_list_iter_const<T> pos)
{
    std::shared_ptr<f_list_node<T>> next_next_value;
    next_next_value = pos._get_node_ptr()->get_next_ptr()->get_next_ptr();

    pos._get_node_ptr()->set_next(next_next_value);

    --_size;
}

template<typename T>
void f_list<T>::erase_after(const f_list_iter_const<T> first,
                            const f_list_iter_const<T> last)
{
    size_t diff = distance(first, last);

    std::shared_ptr<f_list_node<T>> last_ptr = last._get_node_ptr();
    first._get_node_ptr()->set_next(last_ptr);

    _size -= diff - 1;
}

template<typename T>
void f_list<T>::pop_front()
{
    if (_head_ptr)
    {
        _head_ptr = _head_ptr->get_next_ptr();
        --_size;
    }
}

template <typename T>
void f_list<T>::clear()
{
    _head_ptr = nullptr;
    _size = 0;
}


// Operations

template <typename T>
void f_list<T>::splice(f_list<T> &other)
{
    if (is_empty())
    {
        swap(other);
    }
    else
    {
        auto _tail = _get_tail_ptr();
        _tail->set_next(other._head_ptr);
        this->_size += other._size;

        other.clear();
    }
}

template <typename T>
void f_list<T>::swap(f_list<T> & other) noexcept
{
    std::swap(this->_head_ptr, other._head_ptr);
    std::swap(this->_size, other._size);
}

template <typename T>
f_list<T> f_list<T>::unite(const T & value)
{
    return _unite(T(value));
}

template <typename M>
f_list<M> unite(const M & value, const f_list<M> & list)
{
    return _unite(value, list);
}

template <typename T>
f_list<T> f_list<T>::unite(const f_list<T> & other)
{
    return _unite(f_list<T>(other));
}


// Overloaded operator

template<typename T>
bool f_list<T>::operator==(const f_list<T> & other) const
{
    return this->eq(other);
}

template<typename T>
bool f_list<T>::operator!=(const f_list<T> & other) const
{
    return !this->eq(other);
}

template <typename T>
f_list<T> f_list<T>::operator+(const T & value)
{
    return unite(value);
}

template <typename T>
f_list<T> f_list<T>::operator+(T && value)
{
    return unite(value);
}

template <typename M>
f_list<M> operator+(const M & value, const f_list<M> & list)
{
    return unite(value, list);
}

template <typename T>
f_list<T> f_list<T>::operator+(const f_list<T> &other)
{
    return unite(other);
}

template <typename T>
f_list<T> & f_list<T>::operator+=(const T & value)
{
    push_back(value);
    return *this;
}

template <typename T>
f_list<T> & f_list<T>::operator+=(const f_list<T> & other)
{
    push_back(other);
    return *this;
}


//// private

template <typename T>
void f_list<T>::_push_front(T && value)
{
    std::shared_ptr<f_list_node<T>> node;
    try
    {
        node = std::make_shared<f_list_node<T>>(value);
    }
    catch (const std::bad_alloc &e)
    {
        throw f_list_error_bad_alloc(__FILE__, typeid(*this).name(),
                __FUNCTION__, __LINE__);
    }

    node->set_next(_head_ptr);
    _head_ptr = node;

    ++_size;
}

template <typename T>
void f_list<T>::_push_back(T && value)
{
    std::shared_ptr<f_list_node<T>> node;
    try
    {
        node = std::make_shared<f_list_node<T>>(value);
    }
    catch (const std::bad_alloc &e)
    {
        throw f_list_error_bad_alloc(__FILE__, typeid(*this).name(),
                __FUNCTION__, __LINE__);
    }

    if (is_empty())
    {
        _head_ptr = node;
    }
    else
    {
        std::shared_ptr<f_list_node<T>> _tail_ptr = _get_tail_ptr();
        _tail_ptr->set_next(node);
    }

    ++_size;
}

template <typename T>
std::shared_ptr<f_list_node<T>> f_list<T>::_get_tail_ptr() const
{
    // TODO: exception list is empty

    f_list_iter_const<T> it = cbegin();

    if (it == cend())
        return nullptr;

    while (nullptr != it._get_node_ptr()->get_next_ptr())
    {
        ++it;
    }

    return it._get_node_ptr();
}

template <typename T>
f_list<T> f_list<T>::_unite(T && value)
{
    f_list<T> list_copy(*this);

    list_copy.push_back(std::move(value));

    return list_copy;
}

template <typename T>
f_list<T> f_list<T>::_unite(f_list<T> && other)
{
    auto list_copy(*this);

    list_copy.splice(other);

    return list_copy;
}

template <typename M>
f_list<M> _unite(const M & value, const f_list<M> & list)
{
    f_list<M> list_copy(list);
    M value_copy(value);

    list_copy.push_front(value_copy);

    return list_copy;
}

#endif // F_LIST_HPP
