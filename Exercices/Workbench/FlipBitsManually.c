#include <stdio.h>

int main() {
    int t, i, j;
    unsigned int a[32];
    scanf("%d", &t);
    unsigned int b[t];
    for (i=0; i<t; i++){
        scanf("%u", &b[i]);
    }
    for (i=0; i<t; i++){
        a[0-31]=0;
        //j=31;
        //do {
        for(j=31; b[i]>0; j--){
            a[j] = b[i] % 2;
            if (a[j]==0){
                a[j]=1;
            }else a[j]=0;
            b[i] = b[i] / 2;
            //j--;
        }
        //}while(b[i]>0);
        //do {
        for(; j>=0; j--){
            a[j]=1;
            //j--;
            //printf("3 j = %d\n", j);
        }
        //}while(j>=0);
        for (j=0; j<32; j++){
            //printf("j = %d\n", j);
            b[i] = b[i] * 2 + a[j];
        }
        printf("%u\n", b[i]);
    }
    return 0;
}
