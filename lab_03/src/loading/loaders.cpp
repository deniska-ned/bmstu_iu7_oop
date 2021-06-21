#include "loading/loaders.h"

#include <fstream>
#include <iostream>


void file_loader::open(std::string filename)
{
    file_stream.open(filename, std::ios::in);
}

int file_loader::get_num() {
    int num;
    file_stream >> num;
    return num;
}

void file_loader::close() {
    file_stream.close();
}
