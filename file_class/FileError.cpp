//
// Created by zth13 on 2022/12/12.
//

#include "FileError.h"
#include <cstring>
#include <exception>

namespace FileManager
{
    FileError::FileError(int n)
    {
        error_number = n;
        switch (error_number)
        {
            case 1:
                error = "\033[0;31mERROR_NUMBER : 1\nThe file/folder does not exist.\033[0m";
                break;
        }
    }

    const char *FileError::what()
    {
        return error.c_str();
    }

    FileError::FileError(const FileError &fl)
    {
        error_number = fl.error_number;
        error = fl.error;
    }

}