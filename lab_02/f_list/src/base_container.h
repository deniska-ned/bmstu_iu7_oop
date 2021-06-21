#ifndef BASE_CONTAINER_H
#define BASE_CONTAINER_H

#include <cstddef>

class base_container
{
public:
    virtual size_t size() const = 0;
    virtual bool is_empty() const = 0;
    virtual void clear() = 0;
    virtual ~base_container() {}
};

#endif // BASE_CONTAINER_H
