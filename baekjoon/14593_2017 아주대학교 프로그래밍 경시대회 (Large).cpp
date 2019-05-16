// 14592 == 14593
#include <bits/stdc++.h>
using namespace std;

struct participant {
    int num, S, C, L;
    bool operator < (participant other) {
        if (S == other.S) {
            if (C == other.C) {
                return L > other.L;
            }
            return C > other.C;
        }
        return S < other.S;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    participant p[n];
    for (int i=0;i<n;++i) {
        int S, C, L;
        scanf("%d%d%d", &S, &C, &L);
        p[i] = {i+1, S, C, L};
    }
    sort(p, p+n);
    printf("%d", p[n-1].num);
}