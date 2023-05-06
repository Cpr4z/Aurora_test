#include "path.h"

namespace Paths
{
    std::string IPath::getData() const
    {
        return data;
    }

    std::ostream& operator<<(std::ostream &os, const Paths::File &path)
    {
        os << string("f ") << path.getData();
        return os;
    }

    std::ostream& operator<<(std::ostream &os, const Paths::Directory &directory)
    {
        os << string("d ") << directory.getData();
        return os;
    }
}
