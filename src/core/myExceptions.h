#pragma once
#include <iostream>

using namespace std;

namespace Exceptions
{
    class myExceptions : public exception
    {
    public:
        void inputError () const;
        void pathError () const;
    };
}
