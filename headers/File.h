//
// Created by 86186 on 2023/7/27.
//

#ifndef FILEMANAGER_FILE_H
#define FILEMANAGER_FILE_H

#include <string>
#include <vector>

class File
{
public:
    enum Mode
    {
        file, folder
    };
private:
    std::string name;
    std::string path;
    std::vector<std::string> labels;
    Mode mode;

public:
    File() = default;

    [[nodiscard]] Mode f_mode() const { return mode; };

    [[nodiscard]] std::string get_name() const { return name; };

    [[nodiscard]] std::string get_path() const { return path; };

    [[nodiscard]] std::string get_labels() const
    {
        std::string s;
        for (const auto &x: labels)
        {
            s += x;
            s += " ";
        }
        return s;
    }

    File(const char *name, const char *path, const std::vector<std::string> &label, Mode mode);
};


#endif //FILEMANAGER_FILE_H
