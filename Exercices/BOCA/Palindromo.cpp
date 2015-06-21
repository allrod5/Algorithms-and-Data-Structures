#include <iostream>

using namespace std;

int main(){
    string input;
    while(true)
    {
        cin >> input;
        if (input=="#")
            break;
        else if (input == string(input.rbegin(), input.rend()))
            cout << "sim\n";
        else
            cout << "nao\n";
    }
    return 0;
}
