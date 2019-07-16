#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, R, C;
    scanf("%d%d%d", &N, &R, &C);

    bool carrot;
    if (R % 2 == C % 2) carrot = true;
    else carrot = false;

    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            if (carrot) putchar('v');
            else putchar('.');
            carrot = !carrot;
        }
        if (N % 2 == 0) carrot = !carrot;
        putchar('\n');
    }
}