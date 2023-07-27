//
// Created by 86186 on 2023/7/27.
//

#include "File.h"

File::File(const char *_name, const char *_path, const std::vector<std::string>& _label, File::Mode _mode)
{
    name = _name;
    path = _path;
    label = _label;
    mode = _mode;
}
