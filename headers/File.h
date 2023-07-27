//
// Created by 86186 on 2023/7/27.
//

#ifndef FILEMANAGER_FILE_H
#define FILEMANAGER_FILE_H

#include <string>
#include <vector>

class File
{
public:
    enum Mode {file,  folder};
private:
    std::string name;
    std::string path;
    std::vector<std::string> label;
    Mode mode;

public:
    File()=default;
    File(const char * name, const char *path, const std::vector<std::string>& label, Mode mode);
};


#endif //FILEMANAGER_FILE_H
