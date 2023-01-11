//
// Created by beicanyuzhuzhu on 2022/9/17.
//

#include "FileManager.h"
#include <iostream>
#include <windows.h>
#include "../tinyxml/tinyxml2.h"
#include "FileError.h"
namespace FileManager
{
    File::File(const std::string &u_path)
    {

        WIN32_FIND_DATA FindFileData;
        HANDLE hFind;
        data = new file_manager_data;
        hFind = FindFirstFileA(u_path.c_str(), &FindFileData);
        if(hFind != INVALID_HANDLE_VALUE)
            data->path = u_path;
        else
            throw FileError(1);
        if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            data->type = FOlDER;
        else
            data->type = FILE;
        FindClose(hFind);

        auto* fd = new tinyxml2::XMLDocument();
        int error = fd->ErrorID();
        fd->LoadFile("FileManagerData.xml");
        tinyxml2::XMLElement *root = fd->RootElement();
        tinyxml2::XMLElement *node = root->FirstChildElement("file");
        while(node != nullptr)
        {
            const char *a =node->FirstChildElement("path")->GetText();
            if (strcmp(a, u_path.c_str()) == 0)
            {
                if_in_data = true;
                break;
            }
            node = node->NextSiblingElement("file");
        }
    }


    File::File(const File & file)
    {
        data = new file_manager_data;
        *data = *(file.data);
        if_in_data = file.if_in_data;
    }

    std::ostream & operator<<(std::ostream & out, const File &file)
    {
        out << file.data->path << std::endl;
        return out;
    }

    std::ostream &operator<<(std::ostream &out, const File *file)
    {
        out<<"\t"<<"path:"<<file->data->path<<"\n\ttype:";
        if(file->data->type == FILE)
            out<<" file\n\t";
        else
            out<<" folder\n\t";
        if(file->if_in_data)
            out<<"label:"<<file->data->label<<"\n";
        else
            out<<"This file is not managed."<<"\n";

        return out;
    }

    File::~File()
    {
        delete data;
    }

}




