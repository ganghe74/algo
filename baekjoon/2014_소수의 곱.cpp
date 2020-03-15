#include <bits/stdc++.h>
using namespace std;

int K, N, p, cnt, a[100];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    scanf("%d%d", &K, &N);
    for (int i=0;i<K;++i) {
        scanf("%d", &a[i]);
        pq.push(a[i]);
    }
    while (cnt < N) {
        int n = pq.top(); pq.pop();
        if (n == p) continue;
        for (int i=0;i<K;++i)
            if (1LL * n * a[i] < (1LL << 31))
                pq.push(n * a[i]);
        p = n;
        cnt++;
    }
    printf("%d", p);
}
