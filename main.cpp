#include "src/core/myExceptions.h"
#include "src/core/core.h"

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
            auto ptr = new Core::Core (argv[2], argv[4], argv[6]);
            try
            {
                if (ptr->validateStartAndFinishDir())
                {
                    auto engine = ptr->createEngine();
                    engine->search(ptr);
                    engine->showResults();
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
