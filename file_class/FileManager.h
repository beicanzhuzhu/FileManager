//
// Created by beicanyuzhuzhu on 2022/10/1.
//

#ifndef FILE_MANGER_FILEMANAGER_H
#define FILE_MANGER_FILEMANAGER_H

#include <string>

namespace FileManager
{
    enum Type{FILE, FOlDER};
    struct file_manager_data{
        std::string path;
        std::string label;
        Type type;
    };


    class File
    {
    private:
        file_manager_data * data;
        bool if_in_data = false;

    public:
        explicit File(const std::string &u_path);
        File(const File & file);
        const char * path() {return data->path.c_str();};
        friend std::ostream & operator<<(std::ostream & out, const File & file);
        friend std::ostream & operator<<(std::ostream & out, const File * file);
        ~File();
    };

}

#endif //FILE_MANGER_FILEMANAGER_H
