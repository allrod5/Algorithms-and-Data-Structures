#include <iostream>
#include <stdlib.h>

using namespace std;

int cmpfunc(const void *a, const void *b);

int main()
{
    int i, N, M;
    cin >> N >> M;
    int partidas[N];

    for(i=0; i<N; i++)
        cin >> partidas[i];

    qsort(partidas, N, sizeof(int), cmpfunc);

    for(i=0; i<M; i++)
        cout << partidas[i] << endl;

    return 0;
}

int cmpfunc(const void *a, const void *b)
{
   return ( *(int*)b - *(int*)a );
}

