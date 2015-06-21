#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Vertex
{
public:
    // Setter
    void setXY(long a, long b)
    {
        x = a;
        y = b;
    }

    // Getters
    long getX() const {return x;}
    long getY() const {return y;}

private:
    long x, y;
};

//template <typename Vertex>
class Set
{
public:
    // Construction
    Set(int N)
    {
        vertex_set = new Vertex[N];
        i = 0;
    }

    // Adder
    void addVertex(Vertex V)
    {
        *(vertex_set+i) = V;
        i++;
    }

    // Finder
    double findMinDist()
    {
        i--;
        double min_dist = sqrt(pow(vertex_set[i].getX()-vertex_set[i-1].getX(), 2) + pow(vertex_set[i].getY()-vertex_set[i-1].getY(), 2));
        for(i; i>0; i--)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(sqrt(pow(vertex_set[i].getX()-vertex_set[j].getX(), 2) + pow(vertex_set[i].getY()-vertex_set[j].getY(), 2))<min_dist)
                {
                    min_dist = sqrt(pow(vertex_set[i].getX()-vertex_set[j].getX(), 2) + pow(vertex_set[i].getY()-vertex_set[j].getY(), 2));
                }
            }
        }
        return min_dist;
    }

private:
    int i;
    Vertex* vertex_set;
};


int main()
{
    int i, N;
    long a, b;
    Vertex V;
    cin >> N;
    Set U(N);
    for(i=0; i<N; i++)
    {
        cin >> a >> b;
        V.setXY(a, b);
        U.addVertex(V);
    }

    cout << fixed << setprecision(3) << U.findMinDist();

    return 0;
}
