#include <iostream>
using namespace std;

void fastscan(int &x) {
    bool neg=false;
    register int c;
    x = 0;
    c = getchar();
    if(c == '-') {
        neg = true;
        c = getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *= -1;
}

int main() {
    int T, A, B;
    fastscan(T);
    while (T--) {
        fastscan(A);
        fastscan(B);
        printf("%d\n", A+B);
    }
}