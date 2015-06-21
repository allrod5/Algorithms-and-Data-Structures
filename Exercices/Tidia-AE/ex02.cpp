#include <iostream>
#include <string>

bool isPalindrome(std::string s);

int main() {
    std::string s1 = "ovo", s2 = "ABBA", s3 = "ovinho", s4 = "BEATLES";
    std::cout << isPalindrome(s1) << std::endl << isPalindrome(s2) << std::endl << isPalindrome(s3) << std::endl << isPalindrome(s4) << std::endl;
    return 42;
}

bool isPalindrome(std::string s) {
    if(s.length()<2) return true;
    return isPalindrome(s.substr(1,s.length()-2)) && s[0] == s[s.length()-1];
}
