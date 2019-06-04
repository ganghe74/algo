#include <cstdio>
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
    register long long sum = 0;
    register int N, x;
    fastscan(N);
    printf("%d\n", N);
    while (N--) {
        fastscan(x);
        sum += x;
    }
    printf("%lld", sum);
}