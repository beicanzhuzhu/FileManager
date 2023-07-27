//
// Created by bcyz on 2023/7/27.
//
#include "FileError.h"

FileError::FileError(int error)
{
    error_code = error;
}

const char *FileError::what() const noexcept
{
    return "some error";
}
