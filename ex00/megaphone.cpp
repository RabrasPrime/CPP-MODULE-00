#include <iostream>

using namespace std;

int    main(int argc, char** argv)
{
    if (argc <= 2)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" << endl;
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            cout << static_cast<char>(toupper(argv[i][j]));
        }
    }
}
