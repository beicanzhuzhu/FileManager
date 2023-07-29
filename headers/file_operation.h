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
    const tinyxml2::XMLElement * current_path;

    static std::vector<std::string> split_string(std::string, const std::string&);
public:
    explicit FileOperation(const char* path);

    const tinyxml2::XMLElement *new_element(const File &, tinyxml2::XMLElement *);

    void cd(const std::string &);
    File get_file();
    std::vector<File> find_file(const std::string&, const tinyxml2::XMLElement *);
    const tinyxml2::XMLElement * find_path(const std::string &, const tinyxml2::XMLElement *);
    void add(const File&, const std::string&);

};

#endif //FILEMANAGER_FILE_OPERATION_H
