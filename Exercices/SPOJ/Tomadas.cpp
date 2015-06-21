#include <iostream>

using namespace std;

int main()
{
    int i, t, n=0;
    for(i=0; i<4; i++)
    {
        cin >> t;
        n += t-1;
    }
    cout << ++n;
    return 0;
}
