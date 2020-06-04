#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, x, t[500001];
vector<int> a[500001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1;i<=n;++i) {
        scanf("%d", &x);
        pq.push({x, i});
    }

    vector<int> ans;
    while (!pq.empty()) {
        auto [topic, blog] = pq.top(); pq.pop();
        vector<int> ntopics;
        for (int v : a[blog])
            if (t[v]) ntopics.push_back(t[v]);
        sort(ntopics.begin(), ntopics.end());
        int myt = 1;
        for (int x : ntopics)
            if (myt == x) myt++;
        if (topic != myt) {
            puts("-1");
            return 0;
        }
        t[blog] = myt;
        ans.push_back(blog);
    }

    for (int x : ans) printf("%d ", x);
}
