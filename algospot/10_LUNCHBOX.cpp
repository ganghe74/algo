#include <bits/stdc++.h>
using namespace std;

int tc, n, e[10000], m[10000];

int heat() {
    vector<pair<int,int>> order;
    for (int i=0;i<n;++i)
        order.push_back(make_pair(-e[i], i));
    sort(order.begin(), order.end());
    int ret = 0, beginEat = 0;
    for (int i=0;i<n;++i) {
        int box = order[i].second;
        beginEat += m[box];
        ret = max(ret, beginEat + e[box]);
    }
    return ret;
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i=0;i<n;++i)
            scanf("%d", &m[i]);
        for (int i=0;i<n;++i)
            scanf("%d", &e[i]);
        printf("%d\n", heat());
    }
}
