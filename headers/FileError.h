//
// Created by 86186 on 2023/7/27.
//

#ifndef FILEMANAGER_FILEERROR_H
#define FILEMANAGER_FILEERROR_H
#include <exception>

class FileError : public std::exception
{
private:
    int error_code;
public:
    explicit FileError(int error = 0);
    ~FileError() override= default;
    [[nodiscard]] const char * what() const noexcept override;
};


#endif //FILEMANAGER_FILEERROR_H
