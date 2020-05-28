#include <bits/stdc++.h>
using namespace std;

int n, x, a[100010];

void init(vector<int> &a, vector<int> &t, int node, int start, int end) {
    if (start == end) t[node] = a[start];
    else {
        init(a, t, node*2, start, (start+end)/2);
        init(a, t, node*2+1, (start+end)/2+1, end);
        t[node] = max(t[node*2], t[node*2+1]);
    }
}

int query(vector<int> &t, int node, int start, int end, int i, int j) {
    if (i > end || j < start) return -1e9;
    if (i <= start && end <= j) return t[node];
    return max(query(t, node*2, start, (start+end)/2, i, j), query(t, node*2+1, (start+end)/2+1, end, i, j));
}

int main() {
    scanf("%d", &n);

    if (n == 1) {
        puts("0");
        return 0;
    }

    priority_queue<pair<int,int>> pq;
    for (int i=1;i<=n;++i) {
        scanf("%d", &a[i]);
        pq.push({a[i], i});
    }

    vector<int> psum(100010), rpsum(100010), t(400000), rt(400000);
    for (int i=1;i<=n;++i)
        psum[i] = psum[i-1] + a[i];
    for (int i=n;i>0;--i)
        rpsum[i] = rpsum[i+1] + a[i];

    init(psum, t, 1, 1, n);
    init(rpsum, rt, 1, 1, n);

    set<int> SET = {0, n+1};

    int ans = 0;

    while (!pq.empty()) {
        auto [elem, idx] = pq.top(); pq.pop();
        int r = *SET.upper_bound(idx) - 1;
        int l = *(--SET.lower_bound(idx)) + 1;
        SET.insert(idx);
        int rsum = query(t, 1, 1, n, idx, r) - psum[idx];
        int lsum = query(rt, 1, 1, n, l, idx) - rpsum[idx];
        ans = max(ans, rsum+lsum);
    }
    printf("%d", ans);

}
