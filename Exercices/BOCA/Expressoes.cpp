#include <iostream>
#include <stack>
#include <string>
#include <sstream>

std::stack<char> s;

int main() {
    int i;
    std::string line, ok;
    while(true) {
        ok = "sim\n";
        std::getline(std::cin, line);
        if(line=="#") break;
        for(i=0; i<line.size(); i++) {
            if(line[i]=='(' || line[i]=='[' || line[i]=='{') {
                s.push(line[i]);
            } else if(line[i]==')') {
                if(s.empty() || s.top()!='(')
                    ok = "nao\n";
                else
                    s.pop();
            } else if(line[i]==']') {
                if(s.empty() || s.top()!='[')
                    ok = "nao\n";
                else
                    s.pop();
            } else if(line[i]=='}') {
                if(s.empty() || s.top()!='{')
                    ok = "nao\n";
                else
                    s.pop();
            }
        }
        if(!s.empty())
            ok = "nao\n";
        while (!s.empty())
            s.pop();
        std::cout << ok;
    }
    return 0;
}
