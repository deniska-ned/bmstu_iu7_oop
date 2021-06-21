#include "loading/loader_creators.h"


std::shared_ptr<base_loader> file_loader_creator::get_loader()
{
    return std::make_shared<file_loader>();
}
