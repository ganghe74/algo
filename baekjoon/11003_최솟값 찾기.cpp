#include <bits/stdc++.h>
using namespace std;
int N, L, a[5000000];
int main() {
    scanf("%d%d", &N, &L);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    deque<pair<int,int>> dq;
    for (int i=0;i<N;++i) {
        if (!dq.empty() && dq.front().second <= i-L) dq.pop_front();
        while (!dq.empty() && a[i] < dq.back().first) dq.pop_back();
        dq.push_back({a[i], i});
        printf("%d ", dq.front().first);
    }
}