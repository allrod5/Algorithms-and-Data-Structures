#include <iostream>
#include <string>
#include <stack>

using namespace std;

string getItem(string *input, size_t i=0);

int main()
{
    stack<string> operations;
    string input, item;
    while(true)
    {
        cin >> input;
        if(input=="#") break;
        while(input.length()!=1)
        {
            item = getItem(&input);
            //cout << item << endl;
        }
    }
    return 0;
}

string getItem(string *input, size_t i)
{
    string item, next;
    cout << *input << endl;
    if(i<input->length())
        item = input[i];
    else
        return " ";

    if(item==" "||item=="+"||item=="-"||item=="/"||item=="*")
    {
        if(i==0)
            *input = input->substr(1);
        return item;
    }
    else {
        next = getItem(input, i+1);
        if(item==" "||item=="+"||item=="-"||item=="/"||item=="*")
        {
            if(i==0)
                *input = input->substr(1);
            return item;
        } else {
            item += next;
            if(i==0)
            {
                *input = input->substr(item.length());
            }
            return item;
        }
    }
}
