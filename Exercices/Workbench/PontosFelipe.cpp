#include <iostream>
#include <math.h>
#include <deque>

using namespace std;

struct Point {
        long x;
        long y;
};

double d(Point p1, Point p2);

int main() {
        int i, n, k=0;
        cin >> n;

    Point p[n];
        deque<double> dists;

        for(i = 0; i<n; i++) {
                cin >> p[i].x >> p[i].y;
                if(i != 0) {
                        for(int j =0; j<i ; j++) {
                                dists.push_front(d(p[i], p[j]));
                        }
                }
        }


        cout.precision(3);
        deque<double>::iterator minor = dists.begin();

        for(deque<double>::iterator it=dists.begin(); it!=dists.end(); ++it) {
                if(*it < *minor) minor = it;
        }
        cout << fixed << *minor << '\n';


        return 0;
}

double d(Point p1, Point p2) {
        return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}
