#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, s, t;
    vector<pair<int,int>> a;
    priority_queue<int, vector<int>, greater<>> pq;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d%d", &s, &t);
        a.push_back({s, t});
    }
    sort(a.begin(), a.end());
    for (int i=0;i<N;++i) {
        if (!pq.empty() && pq.top() <= a[i].first) pq.pop();
        pq.push(a[i].second);
    }
    printf("%d", pq.size());
}