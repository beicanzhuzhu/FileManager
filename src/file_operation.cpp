//.
// Created by bcyz on 2023/7/27.
//

#include "file_operation.h"

#include <cstring>
#include <d2d1helper.h>

std::vector<std::string> FileOperation::split_string(std::string  str, const std::string& _s)
{
    int size = (int)str.size();
    std::vector<std::string> labels_list;

    str += " ";
    std::string::size_type pos;
    for (int i = 0; i < size; ++i)
    {
        pos = str.find(_s, i);
        if(pos < size)
        {
            std::string s = str.substr(i, pos - i);
            labels_list.push_back(s);
            i = (int)pos;
        }
    }
    return labels_list;
}

FileOperation::FileOperation(const char *_path)
{
    doc.LoadFile(_path);
    root = doc.RootElement();
    current_path = root;
}
/*!
 *
 * @param _path
 */
void FileOperation::cd(const std::string & _path)
{
    current_path = find_path(_path, current_path);
}

/*!
 * 在文件树中寻找指定的文件，并返回所有结果
 * @param name 文件名
 * @param r 查找的目录（默认为根目录，可以不指定）
 * @return 包含所有同名文件的vector
 */
std::vector<File> FileOperation::find_file(const std::string& name, const tinyxml2::XMLElement *r = nullptr)
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
                    split_string(labels, " "),
                    File::folder);
            std::vector<File> result = find_file(name, ptr);
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
                    split_string(labels, " "),
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
void FileOperation::add(const File& f, const std::string & _path)
{
    for (const tinyxml2::XMLElement *ptr = root->FirstChildElement(); ptr != nullptr; ptr = ptr->NextSiblingElement())
    {
        if (strcmp(ptr->Attribute("NAME"), _path.c_str()) == 0)
        {

        }else if (strcmp(ptr->Name(), "folder") == 0)
        {
        }
    }
}
/*!
 * 返回_path指定的路径的xml节点
 * @param _path 要寻找的路径
 * @return 失败返回nullptr
 */
const tinyxml2::XMLElement *FileOperation::find_path(const std::string & _path, const tinyxml2::XMLElement * r = nullptr)
{
    r = (r == nullptr ? root :r);
    auto paths = split_string(_path, "\\");
    auto j = r->FirstChildElement("folder");
    for (const auto& i : paths)
    {
        for (; j != nullptr;j = j->NextSiblingElement("folder"))
        {
            if (strcmp(j->Attribute("NAME"), i.c_str()) == 0)
            {
                j = j->FirstChildElement("folder");
                break;
            }
        }
        if(j== nullptr)
            return nullptr;
    }
    return j;
}

File FileOperation::get_file()
{
    return File{current_path->Attribute("NAME"),
                current_path->Attribute("PATH"),
                split_string(current_path->FirstChildElement("label")->GetText(), " "),
                strcmp(current_path->Name(), "file") ? (File::file) : (File::folder)};
}

const tinyxml2::XMLElement *FileOperation::new_element(const File &f, tinyxml2::XMLElement *x = nullptr)
{
    x = (x == nullptr ? root : x);
    if (strcmp(x->Name(), "folder") != 0) return nullptr;

    tinyxml2::XMLElement *new_e;
    if (f.f_mode() == File::file)
        new_e = doc.NewElement("file");
    else
        new_e = doc.NewElement("folder");

    new_e->SetAttribute("NAME", f.get_name().c_str());
    new_e->SetAttribute("PATH", f.get_path().c_str());
    new_e->SetAttribute("LABEL", f.get_labels().c_str());

    x->InsertEndChild(new_e);

}
