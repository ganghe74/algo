#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    bool star = true;
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            if (star) putchar('*');
            else putchar('.');
            star = !star;
        }
        puts("");
        if (M % 2 == 0) star = !star;
    }
}