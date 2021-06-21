#ifndef LAB_03_DIRECTORS_H
#define LAB_03_DIRECTORS_H

#include "loading/builders.h"
#include "loading/loaders.h"


class base_director
{
public:
    virtual void set_builder(std::shared_ptr<base_builder> builder_ptr) = 0;
    virtual void set_filepath(std::string & filepath);
    virtual void make() = 0;

protected:
    std::string _filepath;
};


class model_director: public base_director
{
public:
    explicit model_director();
    void set_builder(std::shared_ptr<base_builder> builder_ptr) override;
    void make() override;

private:
    std::shared_ptr<base_model_builder> _builder_ptr;
    std::shared_ptr<base_loader> _loader_ptr;
};


class camera_director: public base_director
{
public:
    explicit camera_director();
    void set_builder(std::shared_ptr<base_builder> builder_ptr) override;
    void make() override;

private:
    std::shared_ptr<base_camera_builder> _builder_ptr;
    std::shared_ptr<base_loader> _loader_ptr;
};

#endif //LAB_03_DIRECTORS_H
