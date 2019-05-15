#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {4,8,15,16,23,42};
    vector<int> q(4);
    for (int i=1;i<=4;++i) {
        printf("? %d %d\n", i, i+1);
        fflush(stdout);
        scanf("%d", &q[i-1]);
    }
    do {
        bool ans = true;
        for (int i=0;i<4;++i) {
            if (a[i] * a[i+1] != q[i]) ans = false;
        }
        if (ans) break;
    } while (next_permutation(a.begin(), a.end()));
    printf("! %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5]);
}

// 32 120 240 368

// 15 16 23 42 8 4
// 240 368 966 336