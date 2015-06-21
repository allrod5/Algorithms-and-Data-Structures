#include <iostream>

using namespace std;

int cont=0;

void floodfill(char* mat,int W, int H, int x, int y){

    if((x<W&&y<H&&x>=0&&y>=0)&&(mat->x)->y!='X'){

        cont++;


        if(x+1<W){
            floodfill(mat,W,H,x+1,y);
        }
        if(x-1>=0){
        floodfill(mat,W,H,x-1,y);
        }
        if(y+1<H){
            floodfill(mat,W,H,x,y+1);
        }
        if(y-1>=0){
            floodfill(mat,W,H,x,y-1);
        }
    }

}


int main()
{
    int W,H,x=0,y=0;
    cin>>H;
    cin>>W;
    char mat[W][H], *aux;
    aux = mat;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>mat[i][j];
        }
    }

    while(x!=-1&&y!=-1){
        cin>>x;
        cin>>y;

        floodfill(aux,W,H,x,y);
        cout<<cont;
        cont=0;

    }


    return 0;
}
