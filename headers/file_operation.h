//
// Created by bcyz on 2023/7/27.
//

#ifndef FILEMANAGER_FILE_OPERATION_H
#define FILEMANAGER_FILE_OPERATION_H

#include "tinyxml2.h"
#include "File.h"
#include <string>
#include <vector>

class FileOperation
{
private:
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement *root;

    static std::vector<std::string> get_labels(std::string);
public:
    explicit FileOperation(const char* path);

    std::vector<File> find(const std::string&, const tinyxml2::XMLElement * r);
    void add(File, const std::string&);

};

#endif //FILEMANAGER_FILE_OPERATION_H
