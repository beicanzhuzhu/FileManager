//
// Created by zth13 on 2022/12/12.
//

#ifndef FILEMANAGER_FILEERROR_H
#define FILEMANAGER_FILEERROR_H

#include <exception>
#include <string>

namespace FileManager
{
    class FileError : public std::exception
    {
    private:
        int error_number;
        std::string error;

    public:
        explicit FileError(int n);
        FileError(const FileError & fl);
        const char *what();
        int number() const {return error_number;};

        ~FileError() override = default;
    };
};


#endif //FILEMANAGER_FILEERROR_H
