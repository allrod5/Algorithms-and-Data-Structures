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
        Student getStudent ( int );
        bool areEquivalents ();
    private:
        int i;
        Student** students;
};

int main () {
    string subject;
    int i, N1, N2, N3;
    while ( true ) {
        Registry *R = new Registry ();
        cin >> N1 >> N2 >> N3;
        if ( N1==0 && N2==0 && N3==0 ) break;
        R -> addStudent ( N1 );
        R -> addStudent ( N2 );
        R -> addStudent ( N3 );
        for ( i=0; i<3; i++ )
            while ( cin >> subject ) R -> getStudent ( i ) . addSubject ( subject );
        if ( R -> areEquivalents () ) cout << "sim\n";
        else cout << "nao\n";
    }
    return 42;
}

Student::Student ( int N ) {
    collection = new string[N];
    this -> N = N;
    i = 0;
}

int Student::getN () {
    return N;
}

void Student::addSubject ( string subject ) {
    cout << i << endl;
    *(collection+i) = subject;
    i++;
}

string* Student::getCollection () {
    return collection;
}

Registry::Registry () {
    students = ( Student** ) malloc ( 3 * sizeof ( Student* ) * sizeof (Student) );
    i = 0;
    //students.reserve(3);
}

Registry::~Registry () {
    for ( int it=0; it<3; it++ )
        delete ( *(students+it) );
}

void Registry::addStudent( int N ) {
    *( students + i ) = new Student ( N );
    i++;
}

Student Registry::getStudent ( int i ) {
    return *students[i];
}

bool Registry::areEquivalents () {
    string *c1, *c2;
    bool equivalence[2] = { false, false };
    int n, N1, N2, it1, it2;
    c1 = getStudent( 0 ) . getCollection ();
    N1 = getStudent( 0 ) . getN ();
    for ( n=1; n<3; n++ ) {
        c2 = getStudent( n ) . getCollection ();
        N2 = getStudent( n ) . getN ();
        for ( it1=0; it1<N1; it1++ )
            for ( it2=0; it2<N2; it2++ )
                if ( *(c1+it1) == *(c2+it2) ) equivalence[n-1] = true;
    }
    return equivalence[0] & equivalence[1];
}
