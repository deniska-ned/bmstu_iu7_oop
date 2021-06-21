#ifndef F_LIST_H
#define F_LIST_H

#include <initializer_list>
#include <memory>

#include "base_container.h"
#include "f_list_node.hpp"
#include "f_list_iter.hpp"
#include "f_list_iter_const.hpp"

template <typename T>
class f_list: public base_container
{
public:
    // Member methods

    f_list() = default;
    explicit f_list(const f_list<T> & other);
    explicit f_list(size_t count);
    f_list(const T * arr, size_t arr_size);
    f_list(std::initializer_list<T> init);
    template<class InputIt> f_list(InputIt first, InputIt last);

    f_list(f_list<T> && other) noexcept;

    f_list<T> & operator=(const f_list<T> & other);
    f_list<T> & operator=(f_list<T> && other) noexcept;
    f_list<T> & operator=(std::initializer_list<T> init);

    ~f_list() override = default;

    
    // Iterators

    f_list_iter<T> begin();
    f_list_iter<T> end();

    f_list_iter_const<T> begin() const;
    f_list_iter_const<T> end() const;

    f_list_iter_const<T> cbegin() const;
    f_list_iter_const<T> cend() const;


    // State

    size_t size() const override;
    bool is_empty() const override;


    // Comparison

    bool eq(const f_list<T> & other) const;
    bool ne(const f_list<T> & other) const;

    bool operator==(const f_list<T> & other) const;
    bool operator!=(const f_list<T> & other) const;


    // Appending to begin

    void push_front(const T & value);
    void push_front(T && value);
    void push_front(const f_list<T> & other);


    // Appending to end

    void push_back(const T & value);
    void push_back(T && value);
    void push_back(const f_list<T> & other);

    f_list<T> & operator+=(const T & value);
    f_list<T> & operator+=(const f_list<T> & other);


    // Inserting

    void insert_after(f_list_iter_const<T> pos, const T& value);
    template <class InputIt>
    void insert_after(f_list_iter_const<T> pos, InputIt first, InputIt last);
    void insert_after(f_list_iter_const<T> pos,
                      std::initializer_list<T> ilist);


    // Erasing

    void erase_after(const f_list_iter_const<T> pos);
    void erase_after(const f_list_iter_const<T> first,
                     const f_list_iter_const<T> last);
    void pop_front();
    void clear() override;


    // Unity

    f_list<T> unite(const T & value);
    template <typename M>
    friend f_list<M> unite(const M & value, const f_list<M> & list);
    f_list<T> unite(const f_list<T> & other);

    f_list<T> operator+(const T & value);
    f_list<T> operator+(T && value);
    template <typename M> friend
    f_list<M> operator+(const M & value, const f_list<M> & list);
    f_list<T> operator+(const f_list<T> &other);


    // Splicing

    void splice(f_list<T> &other);


    // Swapping

    void swap(f_list<T> & other) noexcept;


private:
    std::shared_ptr<f_list_node<T>> _head_ptr = nullptr;
    size_t _size = 0;

    void _push_front(T && value);
    void _push_back(T && value);
    std::shared_ptr<f_list_node<T>> _get_tail_ptr() const;

    f_list<T> _unite(T && value);
    f_list<T> _unite(f_list<T> && other);
    template <typename M> friend
    f_list<M> _unite(const M & value, const f_list<M> & list);
};

#endif // F_LIST_H
