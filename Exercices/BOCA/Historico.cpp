#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Student {
    public:
        Student ( int );
        int getN ();
        void addSubject ( string );
        string* getCollection ();
    private:
        int i, N;
        string *collection;
};

class Registry {
    public:
        Registry ();
        ~Registry ();
        void addStudent ( int );
        Student* getStudent ( int );
        bool areEquivalents ();
    private:
        Student** students;
        int i;
};

int main () {
    string subject;
    int i, j, N[3];
    while ( true ) {
        Registry *R = new Registry ();
        cin >> N[0] >> N[1] >> N[2];
        if ( N[0]==0 && N[1]==0 && N[2]==0 ) break;
        R -> addStudent ( N[0] );
        R -> addStudent ( N[1] );
        R -> addStudent ( N[2] );
        for ( i=0; i<3; i++ )
            for ( j=0; j<N[i]; j++ ) {
                cin >> subject;
                R -> getStudent ( i ) -> addSubject ( subject );
            }
        if ( R -> areEquivalents () ) cout << "sim\n";
        else cout << "nao\n";
    }
    return 42;
}

Student::Student ( int N ) {
    collection = new string[N];
    this -> N = N;
    return;
}

int Student::getN () {
    return N;
}

void Student::addSubject ( string subject ) {
    *(collection+i) = subject;
    i++;
    return;
}

string* Student::getCollection () {
    return collection;
}

Registry::Registry () {
    students = ( Student** ) malloc ( 3 * sizeof ( Student* ) * sizeof (Student) );
    //students.reserve(3);
    return;
}

Registry::~Registry () {
    for ( int it=0; it<3; it++ )
        delete ( *( students + it ) );
    return;
}

void Registry::addStudent( int N ) {
    *( students + i ) = new Student ( N );
    i++;
    return;
}

Student* Registry::getStudent ( int i ) {
    return *( students + i );
}

bool Registry::areEquivalents () {
    string *c[2];
    bool equivalent;
    int m, n, N[2], i, j;
    for ( m=0; m<3; m++ ) {
        c[0] = getStudent ( m ) -> getCollection ();
        N[0] = getStudent ( m ) -> getN ();
        for ( n=0; n<3; n++ ) {
            if ( m == n ) continue;
            else {
                c[1] = getStudent ( n ) -> getCollection ();
                N[1] = getStudent ( n ) -> getN ();
                for ( i=0; i<N[0]; i++ ) {
                    equivalent = false;
                    for ( j=0; j<N[1]; j++ ) {
                        if ( *( c[0] + i ) == *( c[1] + j ) ) equivalent = true;
                    }
                    if ( equivalent == false ) return false;
                }
            }
        }
    }
    return true;
}
