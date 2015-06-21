#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, m, x0, y0, x, y, up, sum;

int main(){

	scanf("%d %d", &n, &m);
	scanf("%d %d", &y0, &x0);
	int array[n][m];
	--y0;
	--x0;

	for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(array[i][j]==1 && (i!=y0 || j!=x0)){
                sum = 0;
                if(n==1);
                else if(i==0) sum += array[i+1][j];
                else if(i==n-1) sum += array[i-1][j];
                else sum += array[i-1][j]+array[i+1][j];
                if(m==1);
                else if(j==0) sum += array[i][j+1];
                else if(j==m-1) sum += array[i][j-1];
                else sum += array[i][j-1]+array[i][j+1];
                if(sum == 1){
                    y = i+1;
                    x = j+1;
                    break;
                }
            }
        }
    }


    printf("%d %d", y, x);
    return 0;
}




