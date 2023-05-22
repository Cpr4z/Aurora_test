#pragma once
#include "path.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <filesystem>
#include <vector>
#include <string>
#include <string_view>


using namespace std;

namespace SearchEngine
{
    class Engine;
}

namespace Core
{
    class Core
    {
    private:
        string user_name;
        string group_name;
        string dir_to_search;
        string current_dir;
        uid_t user_id;
        gid_t group_id;
        void findUserId() noexcept;
        void findGroupId() noexcept;
    public:
        Core(const string& user,
             const string& group, const string& dir_to_search);// Search all matches of user and group coincidences
        Core(const string& dir_to_search); // Search all open for reading file
        [[nodiscard]] SearchEngine::Engine* createEngine();
        void setUsername (const string& name) noexcept;
        void setGroup (const string& group) noexcept;
        void setDirToSearch (const string& dir) noexcept;
        string& getUsername () noexcept;
        string& getGroup() noexcept;
        string& getDirToSearch() noexcept;
        string& getCurrentDir() noexcept;
        uid_t& getUserId() noexcept;
        gid_t& getGroupId() noexcept;
        [[nodiscard]] bool validateStartAndFinishDir(); // check is the finish dir contain part of the baseDir
    };

}

namespace SearchEngine
{
    typedef vector<Paths::IPath*> pathVec;
    class Engine
    {
    private:
        pathVec result;
    public:
        void showResults() const noexcept;
        pathVec search(Core::Core *core, const string& str);
        friend class Core::Core;
        friend class Paths::IPath;
    };
}


