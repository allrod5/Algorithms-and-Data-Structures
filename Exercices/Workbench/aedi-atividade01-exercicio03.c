#include <stdio.h>
#include <stdlib.h>

char *inputString(FILE* fp, size_t size);

size_t len = 0;

int main(void){
    char *m, *i;
    int k=0, n=0;

    m = inputString(stdin, 1);

    for(i=m; *i; i++)
    {
        if(k==0 && *i=='a')
            k++;
        else if(k==1 && *i=='t')
            k++;
        else if(k==2 && *i=='g')
            k++;
        else
            k = 0;
        if(k==3)
        {
            n++;
            k=0;
        }
    }

    printf("%d", n);

    free(m);
    return 0;
}

char *inputString(FILE* fp, size_t size){
    char *str;
    int ch;
    str = realloc(NULL, sizeof(char)*size);
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}
