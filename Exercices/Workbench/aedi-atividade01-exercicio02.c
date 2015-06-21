#include <stdio.h>
#include <stdlib.h>

char *inputString(FILE* fp, size_t size);

size_t len = 0;

int main(void){
    char *m, *i;
    int j, pallindrome = 1;
    while(1)
    {
        m = inputString(stdin, 1);
        if(m=="#") break;
        j = len-2;
        for(i=m; *(i+len/2); i++)
        {
            if(*i!=*(i+j))
                pallindrome = 0;
            j -= 2;
        }

        if(pallindrome==0){
            printf("nao");
        } else {
            printf("sim");
        }
    }
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
