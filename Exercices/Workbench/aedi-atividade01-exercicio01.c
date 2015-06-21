#include <stdio.h>

int main() {
    int N, i;
    char answer = 1;
    scanf("%d", &N);
    int v[N];
    for(i = 0; i < N; i++) {
        if(answer==1) {
            scanf("%d", &v[i]);
            if(i!=0 && v[i-1]>v[i]) answer = 0;
        } else scanf("%d");
    }
    if(answer==1) printf("A sequência inserida está ordenada.");
    else printf("A sequência inserida não está ordenada");
    return 0;
}
