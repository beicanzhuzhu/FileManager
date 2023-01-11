#include <iostream>
#include "file_class/FileManager.h"
#include "file_class/FileError.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
using namespace FileManager;


File * work_file;


int main(int argc, char **argv)
{
    system("color");
    switch (argc)
    {
        case 1:
            break;
        case 2:
            try
            {
                work_file = new File(argv[1]);
            }catch(FileError & e)
            {
                cout<<e.what()<<endl;
                exit(e.number());
            }
            cout<<work_file;
            break;
        default:
            break;
    }

    string common;

    cout<<"("<<work_file->path()<<")>";
    cin>>common;

    return 0;
}
