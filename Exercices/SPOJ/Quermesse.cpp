#include <iostream>

using namespace std;

int main()
{
    int i, N, num, ganhador, teste = 0;
    while(true)
    {
        cin >> N;
        if(N==0) break;
        teste++;
        num = 0;
        for(i=0; i<N; i++)
        {
            cin >> num;
            if(num==i+1)
                ganhador = num;
        }
        cout << "Teste " << teste << "\n" << ganhador << "\n\n";
    }
}
