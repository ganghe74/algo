#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d ", &N);
    while (N--) {
        int a = 0, b;
        for (int i=0;i<3;++i) {
            char x = getchar();
            a = a * 26 + x - 'A';
        }
        scanf("-%d ", &b);
        if (abs(a-b) <= 100) puts("nice");
        else puts("not nice");
    }
}