#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include <vector>
#include "objects/object.h"


class composite : public object
{
public:
    composite() = default;
    ~composite() = default;

    bool add(std::shared_ptr<object> obj) override;
    bool remove(long index) override;
    std::vector<std::shared_ptr<object>>::iterator begin();
    std::vector<std::shared_ptr<object>>::iterator end();
    std::vector<std::shared_ptr<object>>::const_iterator cbegin() const;
    std::vector<std::shared_ptr<object>>::const_iterator cend() const;

    void accept(std::shared_ptr<base_visitor> visitor) override;
    bool is_composite() override { return true; };
    bool is_visible() override { return false; };
    void reform(std::shared_ptr<Matrix<double>> reform_mtr) override;

private:
    std::vector<std::shared_ptr<object>> objects;
};

#endif // COMPOSITE_HPP
