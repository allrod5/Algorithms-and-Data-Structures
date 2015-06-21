#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t, n, i, j, k;

    scanf("%d", &t);

    int del[t];
    char v[10001];

    for(i=0; i<t; i++){
        for(k=0; k<10001; k++) v[k]=0;
        scanf("%s", v);
        n=0;
        for(j=0; j<10000; j++){
            if(v[j+1]!=0)
                if(v[j]==v[j+1]) n++;
        }
        del[i]=n;
    }

    for(i=0; i<t; i++) printf("%d\n", del[i]);

    return 0;
}
