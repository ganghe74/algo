#include <bits/stdc++.h>
using namespace std;

class Candidate {
public:
    int n = 0;
    int s = 0;
    int cnt[4] = {};
};

bool operator<(const Candidate& lhs, const Candidate& rhs) {
    return tie(lhs.s, lhs.cnt[3], lhs.cnt[2]) < tie(rhs.s, rhs.cnt[3], rhs.cnt[2]);
}

bool operator==(const Candidate& lhs, const Candidate& rhs) {
    return tie(lhs.s, lhs.cnt[3], lhs.cnt[2]) == tie(rhs.s, rhs.cnt[3], rhs.cnt[2]);
}

int main() {
    Candidate c[3];
    c[0].n = 1; c[1].n = 2; c[2].n = 3;

    int N, x;
    scanf("%d", &N);
    while (N--) {
        for (int i=0;i<3;++i) {
            scanf("%d", &x);
            c[i].s += x;
            c[i].cnt[x]++;
        }
    }

    sort(c, c+3);

    if (c[1] == c[2]) printf("0 %d", c[2].s);
    else printf("%d %d", c[2].n, c[2].s);
}