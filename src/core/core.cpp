#include "core.h"

Core::Core::Core (str dir_to_search, str user, str group) : dir_to_search(dir_to_search),
                                                user_name(user), group_name(group)
{
    Core::Core::current_dir = filesystem::current_path();
}

Core::Core::Core (str dir_to_search) : dir_to_search(dir_to_search)
{
    Core::Core::current_dir = filesystem::current_path();
}

void Core::Core::changeCurrentDir()
{
    filesystem::
}


pathList SearchEngine::Engine::search()
{
    stat()
}
