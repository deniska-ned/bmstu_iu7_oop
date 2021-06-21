#ifndef LAB_03_BUILDERS_H
#define LAB_03_BUILDERS_H

#include "objects/model.h"


class base_builder
{
public:
    virtual void reset() = 0;
    virtual std::shared_ptr<object> get_result() = 0;
};

class base_model_builder: public base_builder
{
public:
    void reset() override = 0;
    virtual void build_points(std::vector<point> points) = 0;
    virtual void build_edges(std::vector<edge> edges) = 0;
    std::shared_ptr<object> get_result() override = 0;
};


class model_builder: public base_model_builder
{
public:
    void reset() override;
    void build_points(std::vector<point> points) override;
    void build_edges(std::vector<edge> edges) override;
    std::shared_ptr<object> get_result() override;

private:
    model_units _details;
};

class base_camera_builder: public base_builder
{
public:
    void reset() override = 0;
    virtual void build_position(int x, int y, int z) = 0;
    virtual void build_angles(int x, int y, int z) = 0;
    std::shared_ptr<object> get_result() override = 0;
};


class camera_builder: public base_camera_builder
{
public:
    void reset() override;
    void build_position(int x, int y, int z) override;
    void build_angles(int x, int y, int z) override;
    std::shared_ptr<object> get_result() override;

private:
    point _position;
    point _angles;
};


#endif //LAB_03_BUILDERS_H
