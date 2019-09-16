#include <iostream>

int main()
{

#if 0
    std::cout << "Hellow World." << std::endl;
#endif

#if 0
    using std::cout;	
    using std::endl;	
    cout << "Hellow World." << endl;
#endif

    using namespace std;
    cout << "Hellow World." << endl;

    return 0;
}