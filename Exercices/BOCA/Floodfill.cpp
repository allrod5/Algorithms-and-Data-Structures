#include <iostream>
#include <string>
#include <stack>

using namespace std;

// structures declaration
struct vertex{int x; int y;};

// functions declarations
int floodfill(char **canvas, vertex v, int L, int C);
void stackNeighbors(stack<vertex> *paint, vertex v);

int main(){
    // variables declaration and initialization
    int i, j, L, C, r;
    char **canvas;
    vertex v;
    cin >> L >> C;
    canvas = new char *[L];
    for(int i = 0; i < C; i++)
        canvas[i] = new char[L];

    for(i=0; i<L; i++)
        for(j=0; j<C; j++)
            cin >> canvas[i][j];

    // getting starting vertexes
    while(true)
    {
        cin >> v.x >> v.y;
        if(v.x==-1) break;
        v.x--;
        v.y--;
        cout << floodfill(canvas, v, L, C) << endl; // requesting floodfill count
    }
    return 0;
}

int floodfill(char **canvas, vertex v, int L, int C)
{
    // variables declaration
    stack<vertex> paint;
    int c = 0;

    // flood neighborhood
    while(true)
    {
        if(v.x<0 || v.x==C || v.y<0 || v.y==L || canvas[v.x][v.y]=='x') {} // if vertex doesn't exist or it's already painted skip
        else
        {
            canvas[v.x][v.y] = 'x';  // paint vertex
            c += 1;
            stackNeighbors(&paint, v); // put neighbors in stack
        }
        if(paint.empty()) return c;
        v = paint.top(); // update v with stack's top
        paint.pop(); // update stack
    }
}

void stackNeighbors(stack<vertex> *paint, vertex v)
{
    v.x--;          // left
    paint->push(v);
    v.x += 2;       // right
    paint->push(v);
    v.x--;
    v.y++;          // up
    paint->push(v);
    v.y -= 2;       // down
    paint->push(v);
    v.y++;
}
