#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
    int N;
    scanf("%d", &N);
    while (N > 0) {
        a[N % 10]++;
        N /= 10;
    }
    if (!(a[3] || a[4] || a[5] || a[6] || a[7] || a[9])) {
        if (a[2] && a[0] && a[1] && a[8]) {
            if (a[2] == a[0] && a[0] == a[1] && a[1] == a[8]) {
                puts("8");
            }
            else {
                puts("2");
            }
        }
        else {
            puts("1");
        }
    }
    else {
        puts("0");
    }
}