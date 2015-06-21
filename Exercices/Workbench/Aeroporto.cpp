#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, v, x, y, i, aero[100000] = {0}, n=1, valor;

    while(1){

        scanf("%d",&a);
        scanf("%d",&v);

        if(a==0||v==0){
            break;
        }

        for(i=0;i<v;i++){
            scanf("%d",&x);
            scanf("%d",&y);

            aero[--x]++;
            aero[--y]++;
        }

        valor=0;

        for(i=0;i<a;i++){
            if(aero[i]>valor){
                valor=aero[i];
            }
        }

        printf("Teste %d\n",n);
        n++;

        for(i=0;i<a;i++){
            if(aero[i]==valor){
                printf("%d ",i+1);
            }
        }

        printf("\n\n");

        for(i=0;i<a;i++){
            aero[i]=0;
        }
    }

    return 0;
}



