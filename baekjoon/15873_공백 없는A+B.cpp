#include <bits/stdc++.h>
using namespace std;
int main() {
    int A = 0, B = 0;
    char x;
    while ((x = getchar()) != EOF) {
        if (!isdigit(x)) continue;
        if (A * 10 + x -'0' <= 10) {
            A = A * 10 + x - '0';
        }
        else {
            B = B * 10 + x - '0';
        }
    }
    printf("%d", A + B);
}