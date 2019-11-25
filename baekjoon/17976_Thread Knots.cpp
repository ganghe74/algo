#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> a;

bool check(int l) {
    int before = a[0].first;
    bool flag = true;
    for (int i=1;i<a.size();++i) {
        if (before + l > a[i].first + a[i].second) return false;
        before = max(a[i].first, before + l);
    }
    return true;
}

int main() {
    unsigned int n, x, l, r;
    scanf("%u", &n);
    for (int i=0;i<n;++i) {
        scanf("%u%u", &x, &l);
        a.push_back({x, l});
    }
    sort(a.begin(), a.end());
    l = 0; r = 2e9;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    while (check(l+1)) l++;
    while (!check(l)) l--;
    printf("%u", l);
}