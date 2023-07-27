//
// Created by bcyz on 2023/7/27.
//

#include "file_operation.h"

#include <cstring>

std::vector<std::string> FileOperation::get_labels(std::string  labels)
{
    int size = (int)labels.size();
    std::vector<std::string> labels_list;

    labels += " ";
    std::string::size_type pos;
    for (int i = 0; i < size; ++i)
    {
        pos = labels.find((std::string)" ",i);
        if(pos < size)
        {
            std::string s = labels.substr(i, pos -i);
            labels_list.push_back(s);
            i = (int)pos;
        }
    }
    return labels_list;
}

FileOperation::FileOperation(const char *path)
{
    doc.LoadFile(path);
    root = doc.RootElement();
}
/*!
 * 在文件树中寻找指定的文件，并返回所有结果
 * @param name 文件名
 * @param r 查找的目录（默认为根目录，可以不指定）
 * @return 包含所有同名文件的vector
 */
std::vector<File> FileOperation::find(const std::string& name, const tinyxml2::XMLElement *r = nullptr)
{
    std::vector<File> f_list;
    if (root->FirstChildElement() == nullptr)
        return std::vector<File>(0);
    r = (r == nullptr ? root :r);
    for(const tinyxml2::XMLElement * ptr = r->FirstChildElement(); ptr != nullptr; ptr = ptr->NextSiblingElement())
    {
        if(strcmp(ptr->Name(), "folder") == 0)
        {
            std::string labels = ptr->FirstChildElement("label")->GetText();
            f_list.emplace_back(
                    ptr->Attribute("NAME"),
                    ptr->Attribute("PATH"),
                    get_labels(labels),
                    File::folder);
            std::vector<File> result = find(name, ptr);
            f_list.insert(f_list.end(),result.begin(), result.end());
        }else if(strcmp(ptr->Name(), "label") == 0)
        {
             continue;
        }else if (strcmp(ptr->Attribute("NAME"), name.c_str()) == 0)
        {
            std::string labels = ptr->FirstChildElement("label")->GetText();
            f_list.emplace_back(
                    ptr->Attribute("NAME"),
                    ptr->Attribute("PATH"),
                    get_labels(labels),
                    File::file);
        }
    }

    return f_list;
}
/*!
 * 在文件树中添加文件或文件夹
 * @param f 要添加的文件或文件夹
 * @param path 要添加到的目录
 */
void FileOperation::add(File f, const std::string & path)
{
    for (const tinyxml2::XMLElement *ptr = root->FirstChildElement(); ptr != nullptr; ptr = ptr->NextSiblingElement())
    {
        if (strcmp(ptr->Attribute("NAME"), path.c_str()) == 0)
        {

        }else if (strcmp(ptr->Name(), "folder") == 0)
        {
        }
    }
}




