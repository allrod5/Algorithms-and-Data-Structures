#include <iostream>

using namespace std;

bool isPrime(unsigned long n);

int main()
{
    int n;
    cin >> n;
    if(isPrime(n))
        cout << "sim";
    else
        cout << "nao";

    return 0;
}

bool isPrime(unsigned long n) {
    if (n <= 3) {
        return n > 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    } else {
        for (unsigned short i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}
