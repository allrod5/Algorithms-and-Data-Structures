#include <stdio.h>

int main() {
    int T, i;
    scanf("%d", &T);
    unsigned int list[T];

    for(i=0; i<T; i++) {
        scanf("%u", &list[i]);
        list[i] = ~ list[i];
    }
    for(i=0; i<T; i++) {
        printf("%u\n", list[i]);
    }


    return 0;
}
