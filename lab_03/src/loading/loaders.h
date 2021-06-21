#ifndef LAB_03_LOADERS_H
#define LAB_03_LOADERS_H

#include <string>
#include <memory>
#include <fstream>


class base_loader
{
public:
    virtual void open(std::string src_name) = 0;
    virtual int get_num() = 0;
    virtual void close() = 0;

    virtual ~base_loader() = default;
};


class file_loader: public base_loader
{
public:
    void open(std::string filename) override;
    int get_num() override;
    void close() override;

private:
    std::ifstream file_stream;
};


#endif //LAB_03_LOADERS_H