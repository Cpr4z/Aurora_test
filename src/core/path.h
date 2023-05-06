#pragma once
#include <string>

using namespace std;

namespace Paths
{
    class IPath
    {
    public:
        explicit IPath(const string& data ) : data(data){}
        string getData() const;
    private:
        string data;
    };


    class File : public IPath
    {
    public:
        explicit File(const string& data): IPath(data){}
        friend std::ostream& operator<<(std::ostream& os, const IPath& path) ;
    private:
        string data;
    };

    class Directory : public IPath
    {
    public:
        explicit Directory(const string& data): IPath(data){}
        friend std::ostream& operator<<(std::ostream& os, const IPath& obj);
    private:
        string data;
    };
}

