#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "argc: " << argc << endl;
    if (argc > 1)// если передаем аргументы, то argc будет больше 1(в зависимости от кол-ва аргументов)
    {
        for (size_t i = 0; i < argc; i++)
        {
            cout << setw(2) << i << ": " << argv[i] << endl;
        }
    	
    }
    else
    {
        cout << "Not arguments" << endl;
    }
    // system("pause");
    return 0;
}