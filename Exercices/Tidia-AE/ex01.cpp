#include <iostream>

int summation(int N);
int min(int v[], int i);
int sum(int v[], int i);
bool isOrdered(int* v, int i);

int main() {
    int v1[10] = {37, 5, 4, 8, 12, -10, 23, -20, 30, 35};
    int v2[10] = {-1, 0, 2, 3, 4, 7, 14, 28, 29, 50};
    std::cout << summation(6) << std::endl;
    std::cout << min(v1, 9) << std::endl;
    std::cout << sum(v1, 9) << std::endl;
    std::cout << isOrdered(v1, 9) << std::endl;
    std::cout << isOrdered(v2, 9) << std::endl;
    return 42;
}

int summation(int N) {
    if(N==1) return 1;
    return N+summation(N-1);
}

int min(int v[], int i) {
    if(i==0) return v[0];
    int aux = min(v, i-1);
    return aux<v[i] ? aux:v[i];
}

int sum(int v[], int i) {
    if(i==0) return v[i];
    return sum(v, i-1)+v[i];
}

bool isOrdered(int* v, int i) {
    if(i==1) return v[1]>v[0];
    return isOrdered(v, i-1) && v[i]>v[i-1];
}
