#pragma once
#include <string_view>

class IPath
{
private:
    enum
    {
        file = 'f', // 0
        directory = 'd', // 1
    };
public:
};


class Path : public IPath
{
private:

};

class Directory : public IPath
{

};