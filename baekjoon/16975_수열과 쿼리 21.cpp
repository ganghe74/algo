#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, M, op, i, j, k, x;
lint t[100002];

lint sum(int pos) {
    lint ret = 0;
    while (pos > 0) {
        ret += t[pos];
        pos &= (pos-1);
    }
    return ret;
}

void add(int pos, int val) {
    while (pos <= N) {
        t[pos] += val;
        pos += (pos & -pos);
    }
}

int main() {
    scanf("%d", &N);
    ++N;
    for (int i=1;i<N;++i) {
        scanf("%d", &x);
        add(i, x);
        add(i+1, -x);
    }
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &i, &j, &k);
            add(i, k);
            add(j+1, -k);
        }
        else {
            scanf("%d", &x);
            printf("%lld\n", sum(x));
        }
    }
}
