#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool areEquivalents();

vector<vector<string>> v;

int main() {
    string subject;
    vector<string> tmp;
    int i, j, N[3];
    while (true) {
        cin >> N[0] >> N[1] >> N[2];
        if (N[0]==0 && N[1]==0 && N[2]==0) break;
        for (i=0; i<3; i++) {
            for (j=0; j<N[i]; j++) {
                cin >> subject;
                tmp.push_back(subject);
            }
            v[i].push_back(tmp);
        }
        if (areEquivalents()) cout << "sim\n";
        else cout << "nao\n";
    }
    return 42;
}

bool areEquivalents() {
    int i;
    bool equivalence[2] = {false, false}, aux;
    for(i=1; i<3; i++) {
        for(string j:v[0]) {
            aux = false;
            for(string k:v[i+1]) {
                cout << j << " " << k << endl;
                if(j.compare(k)) aux = true;
            }
            if(!aux) return false;
        }
    }
    return aux;
}
