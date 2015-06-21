#include <iostream>

struct Param {
    int* vector;
    int length;
};

Param getv();
int summation(int N);
int min(Param p);
int sum(Param p);
bool isOrdered(Param p);

int main() {
    int option;
    while(true) {
        std::cout << "\nChoose wisely:\n\n\t1 - Calculate summation from 1 to N\n\t2 - Get minimum value of a vector\n\t3 - Get sum from the elements of a vector\n\t4 - Check if vector is ordered\n\t5 - End with this miserable program life\n\n";
        std::cin >> option;
        switch(option) {
            case 1:
                int N;
                std::cout << "\nEnter the number which to sum up to: ";
                std::cin >> N;
                std::cout << summation(N) << std::endl;
                break;
            case 2:
                std::cout << min(getv()) << std::endl;
                break;
            case 3:
                std::cout << sum(getv()) << std::endl;
                break;
            case 4:
                std::cout << isOrdered(getv()) << std::endl;
                break;
            case 5:
                return 42;
                break;
            default:
                std::cout << "\nEnter with an integer from 1 to 5.\n";
                break;
        }
    }
}

Param getv() {
    int n, i;
    Param p;
    std::cout << "\nEnter with the size the vector: ";
    std::cin >> n;
    int *v = (int*) malloc(n*sizeof(int));
    std::cout << "\nEnter the vector's elements: ";
    for(i=0; i<n; i++)
        std::cin >> v[i];
    p.vector = v;
    p.length = n-1;
    return p;
}

int summation(int N) {
    if(N==1) return 1;
    return summation(N-1) + N;
}

int min(Param p) {
    int m;
    if(p.length==0) return p.vector[0];
    p.length--;
    m = min(p);
    return m < p.vector[++p.length] ? m : p.vector[++p.length];
}

int sum(Param p) {
    if(p.length==0) return p.vector[0];
    p.length--;
    return sum(p) + p.vector[++p.length];
}

bool isOrdered(Param p) {
    bool A, B;
    if(p.length==1) return true;
    if(p.vector[p.length-1] == p.vector[p.length-2]) {
        A = p.vector[p.length] > p.vector[p.length-2];
        if(p.length>2) B = p.vector[p.length] > p.vector[p.length-3];
        else B = A;
    } else {
        A = p.vector[p.length] > p.vector[p.length-1];
        B = p.vector[p.length] > p.vector[p.length-2];
        if(p.vector[p.length] == p.vector[p.length-1] || p.vector[p.length] == p.vector[p.length-2]) return p.length-- && isOrdered(p);
    }
    return A==B && p.length-- && isOrdered(p);
}
