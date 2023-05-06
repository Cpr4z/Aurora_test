#include "core/myExceptions.h"
#include "core/core.h"
#include <memory>

int main(int argc, char* argv[])
{
    // sudo mycheckperm -u username -g groupname -p path
    try
    {
        if (argc != 7)
        {
            throw(Exceptions::myExceptions());
        }
        else
        {
//            Core::Core *core = new Core(argv[2], argv[4], argv[6]);
            auto ptr = make_unique<Core::Core>
                    (argv[2], argv[4], argv[6]);
            try
            {
                if (ptr->validateStartAndFinishDir())
                {
                    ptr->createEngine();
                }
                else
                {
                    throw (Exceptions::myExceptions());
                }
            }
            catch (const Exceptions::myExceptions& ex)
            {
                ex.pathError();
            }
        }
    }
    catch (const Exceptions::myExceptions& ex)
    {
        ex.inputError();
    }
    return 0;
}
