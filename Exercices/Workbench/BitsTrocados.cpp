#include <iostream>

using namespace std;

int main()
{
    int V, I, J, K, teste=0;

    while(true)
    {
        cin >> V;
        if(V==0)
            break;
        teste++;
        I = V/50;
        V -= I*50;
        J = V/10;
        V -= J*10;
        K = V/5;
        V -= K*5;
        cout << "Teste " << teste << "\n" << I << " " << J << " " << K << " " << V << "\n\n";
    }
    return 0;
}
