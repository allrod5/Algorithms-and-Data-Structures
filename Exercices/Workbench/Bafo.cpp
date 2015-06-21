#include <iostream>

using namespace std;

int main()
{
    int N, Aldo, Beto, a, b, teste=0;

    while(true)
    {
        cin >> N;
        if(N==0)
            break;
        teste++;
        Aldo = 0;
        Beto = 0;
        for(int i=0; i<N; i++)
        {
            cin >> a >> b;
            Aldo += a;
            Beto += b;
        }
        if(Aldo>Beto)
            cout << "Teste " << teste << "\nAldo\n\n";
        else
            cout << "Teste " << teste << "\nBeto\n\n";
    }
    return 0;
}
