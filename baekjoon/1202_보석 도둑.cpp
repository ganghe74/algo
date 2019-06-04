#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    priority_queue<pair<int,int>> pq;
    while (N--) {
        int M, V;
        scanf("%d%d", &M, &V);
        pq.push({V, M});
    }
    multiset<int> s;
    while (K--) {
        int C;
        scanf("%d", &C);
        s.insert(C);
    }
    long long ans = 0;
    while (!pq.empty() && !s.empty()) {
        int M = pq.top().second;
        int V = pq.top().first;
        pq.pop();
        auto it = s.lower_bound(M);
        if (it != s.end()) {
            ans += V;
            s.erase(it);
        }
    }
    printf("%lld", ans);
}