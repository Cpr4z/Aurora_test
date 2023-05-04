#pragma once
#include "path.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <filesystem>
#include <forward_list>
#include <string>
#include <string_view>


using namespace std;

namespace Core
{
    typedef string_view str;

    class Core
    {
    private:
        str current_dir;
        str dir_to_search;
        str user_name;
        str group_name;

    public:
        explicit Core(str dir_to_search,
             str user, str group);// Search all matches of user and group coincidences
        explicit Core(str dir_to_search); // Search all open for reading file
        void changeCurrentDir();
        void showSutableDirsAndFiles();

    };

}

namespace SearchEngine
{
    typedef forward_list<Ipath*> pathList;
    class Engine
    {
    private:
        pathList result;
        struct Buf;

    public:
        pathList search();

    };
}


