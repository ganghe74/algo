#include <bits/stdc++.h>
using namespace std;

bool A[100001], B[100001];
int main() {
    int l = 0;
    char x;
    while ((x = getchar()) != '\n') {
        if (x == '1') A[l] = 1;
        l++;
    }
    for (int i=0;i<l;++i) {
        x = getchar();
        if (x == '1') B[i] = 1;
    }
    for (int i=0;i<l;++i) printf("%d", A[i] & B[i]);
    puts("");
    for (int i=0;i<l;++i) printf("%d", A[i] | B[i]);
    puts("");
    for (int i=0;i<l;++i) printf("%d", A[i] ^ B[i]);
    puts("");
    for (int i=0;i<l;++i) printf("%d", !A[i]);
    puts("");
    for (int i=0;i<l;++i) printf("%d", !B[i]);
}