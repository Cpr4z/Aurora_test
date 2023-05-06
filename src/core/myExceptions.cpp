#include "myExceptions.h"

namespace Exceptions
{
    void myExceptions::inputError() const
    {
        cout << "Incorrect parametrs for script " << endl;
    }

    void myExceptions::pathError() const
    {
        cout << "Current dir isn't a part of the search dir" << endl;
    }
}