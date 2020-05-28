#include <bits/stdc++.h>
using namespace std;

int tc, n;

int concat(const vector<int> &lengths) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0;i<lengths.size();++i)
        pq.push(lengths[i]);
    int ret=0;
    while (pq.size() > 1) {
        int min1 = pq.top(); pq.pop();
        int min2 = pq.top(); pq.pop();
        pq.push(min1 + min2);
        ret += min1 + min2;
    }
    return ret;
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        vector<int> a(n);
        for (int i=0;i<n;++i)
            scanf("%d", &a[i]);
        printf("%d\n", concat(a));
    }
}
