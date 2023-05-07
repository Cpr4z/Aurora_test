#include "core.h"
#include "myExceptions.h"
#include "path.h"

using cr = Core::Core;

cr::Core (const string& username, const string& group, const string& dir_to_search)
            : user_name(username), group_name(group), dir_to_search(dir_to_search)
{
    current_dir = filesystem::current_path().string();
}

cr::Core (const string& dir_to_search) : dir_to_search(dir_to_search)
{
    current_dir = filesystem::current_path().string();
}

SearchEngine::Engine* cr::createEngine()
{
    return new SearchEngine::Engine();
}

void cr::setUsername(const string &name) noexcept
{
    user_name = name;
}

void cr::setGroup(const string &group) noexcept
{
    group_name = group;
}

void cr::setDirToSearch(const string &dir) noexcept
{
    dir_to_search = dir;
}

string& cr::getUsername() noexcept
{
    return user_name;
}

string& cr::getCurrentDir() noexcept
{
    return cr::current_dir;
}

string& cr::getGroup() noexcept
{
    return cr::group_name;
}

string& cr::getDirToSearch() noexcept
{
    return cr::dir_to_search;
}

uid_t& cr::getUserId() noexcept
{
    return cr::user_id;
}

gid_t& cr::getGroupId() noexcept
{
    return cr::group_id;
}

void cr::findUserId() noexcept
{
    auto userInfo = getpwnam(user_name.c_str());
    user_id = userInfo->pw_uid;
}

void cr::findGroupId() noexcept
{
    auto groupInfo = getpwnam(group_name.c_str());
    user_id = groupInfo->pw_uid;
}

bool cr::validateStartAndFinishDir() //     /home/myname   home/myname/testdir/
{
    auto it1 = cr::current_dir.begin();
    auto it2 = cr::dir_to_search.begin();
    while (it1 != cr::current_dir.end())
    {
        if (*it1 == *it2)
        {
            ++it1;
            ++it2;
        }
        else
        {
            try {
                throw(Exceptions::myExceptions());
            }
            catch (const Exceptions::myExceptions& ex)
            {
                ex.pathError();
            }
            return false;
        }
    }
    return true;
}

namespace SearchEngine
{
    pathVec Engine::search(Core::Core *core)
    {
        for (const auto& file: filesystem::directory_iterator(core->getDirToSearch()))
        {
            if (file.path().string().find("/sys/") || file.path().string().find("/proc/")) // if path contains /sys/ /proc/ we will skip it
            {
                core->setDirToSearch(file.path().string()); //
                search(core);
            }
            else {
                struct stat *st= new struct stat();
                lstat(file.path().string().c_str(), st); // get information about file
                // required conditions
                if ((st->st_uid == core->getUserId() && st->st_mode == S_IWUSR ) ||
                    (st->st_gid == core->getGroupId() && st->st_mode == S_IWGRP) ||
                    (st->st_mode == S_IWOTH ))
                {
                    if (filesystem::is_directory(file)) // if object is directory
                    {
                        core->setDirToSearch(file.path().string());
                        delete st;
                        search(core);
                        result.push_back(new Paths::Directory(file.path().string())); // create new object directory
                    } else // if object is file
                    {
                        result.push_back(new Paths::File(file.path().string()));
                        delete st;
                    }
                }
                else
                {
                    core->setDirToSearch(file.path().string());
                    delete st;
                    search(core);
                }
            }
        }

        return result;
    }

    void Engine::showResults() const noexcept
    {
        if (result.empty())
        {
            cout << "No files and dirs were found" << endl;
        }else
        {
            for(const auto& file : result)
            {
            cout << file << endl;
            }
        }
    }
}


