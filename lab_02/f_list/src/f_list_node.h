#ifndef F_LIST_NODE_H
#define F_LIST_NODE_H

#include <memory>

template <typename T>
class f_list_node
{
public:
    // Member methods

    f_list_node() = default;
    explicit f_list_node(T &data);
    explicit f_list_node(const f_list_node<T> & other);

    f_list_node(f_list_node<T> && other) noexcept;

    f_list_node<T> & operator=(const f_list_node<T> & other);
    f_list_node<T> & operator=(f_list_node<T> && other) noexcept;

    ~f_list_node() = default;


    // Operations

    void swap(f_list_node<T> & other) noexcept;


    // Getters

    T& get_data();
    const T& get_data() const;
    std::shared_ptr<f_list_node<T>> get_next_ptr() const;


    // Setters

    void set_data(const T & data);
    void set_next(std::shared_ptr<f_list_node<T>> next_ptr);



private:
    T _data = T();
    std::shared_ptr<f_list_node<T>> _next_ptr = nullptr;
};

#endif // F_LIST_NODE_H
