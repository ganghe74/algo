#include <bits/stdc++.h>
using namespace std;

int A, B, a[10], b[10];
char s[10];

int main() {
    for (int i=0;i<10;++i) scanf("%d", &a[i]);
    for (int i=0;i<10;++i) scanf("%d", &b[i]);
    for (int i=0;i<10;++i) {
        if (a[i] > b[i]) {
            A += 3;
            s[i] = 'A';
        }
        else if (a[i] < b[i]) {
            B += 3;
            s[i] = 'B';
        }
        else {
            A++; B++;
            s[i] = 'D';
        }
    }
    printf("%d %d\n", A, B);
    if (A > B) puts("A");
    else if (A < B) puts("B");
    else {
        char x;
        for (int i=9;i>=0;--i) {
            if (s[i] == 'D') continue;
            printf("%c", s[i]);
            return 0;
        }
        puts("D");
    }
}