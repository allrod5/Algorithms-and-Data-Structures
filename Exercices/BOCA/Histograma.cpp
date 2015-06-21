#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int i, M, N, P;
    while(true)
    {
        cin >> M >> N;
        if (M==0) break;
        M *= N;
        cin >> P;
        int hist[P+1];
        memset( hist, 0, (P+1)*sizeof(int) );
        for(i = 0; i < M; i++)
        {
            cin >> N;
            hist[N]++;
        }
        for(i = 0; i<=P; i++)
        {
            cout << i << ":" << hist[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
