#include <iostream>
#include <stdint.h>

using namespace std;

int main()
{
    int32_t n, i, a, b;
    bool ord;
    while(true)
    {
        cin >> n;
        if(n==0) break;
        ord = true;
        cin >> a;
        for(i=1; i<n; i++)
        {
            cin >> b;
            if(ord && a>=b)
                ord = false;
            a = b;
        }
        if(ord)
            cout << "sim" << endl;
        else
            cout << "nao" << endl;
    }
    return 0;
}
