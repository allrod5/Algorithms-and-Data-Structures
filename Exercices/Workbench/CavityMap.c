#include <stdio.h>

void depictCavities(char **map, int n);
int checkNeighborhood(char **map, int i, int j);

int main() {
    /* variables declaration */
    int n, i, j;
    char **map;
    /* read map dimension */
    scanf("%d", &n);
    /* allocate space for the map and fill it */
    map = malloc(sizeof(char*) * n);            /* make room for columns    */
    for(i=0; i<n; i++) {                        /* for each column          */
        *(map+i) = malloc(sizeof(char) * n);    /* make room for rows       */
        for(j=0; j<n; j++)                      /* for each cell        */
            scanf(" %c", &map[i][j]);           /* fill it with input   */
    }
    depictCavities(map, n);
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++)
            printf("%c", map[i][j]);
        if(i<n-1) printf("\n");
    }
    return 0;
}

void depictCavities(char **map, int n) {
    int i, j;
    for(i=1; i<n-1; i++) {
        for(j=1; j<n-1; j++) {
            if(checkNeighborhood(map, i, j)==1) {
                map[i][j] = 'X';
            }
        }
    }
    return;
}

int checkNeighborhood(char **map, int i, int j) {
    if(map[i-1][j]<map[i][j] && map[i][j-1]<map[i][j] && map[i+1][j]<map[i][j] && map[i][j+1]<map[i][j]) return 1;
    else return 0;
}
