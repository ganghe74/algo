#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 1e18;
int c, n, k;
int cacheLen[505], cacheCnt[505], S[505];
int lis(int start) {
    int &ret = cacheLen[start + 1];
    if (ret != -1) return ret;
    ret = 1;
    for (int next = start + 1; next <= n; ++next)
        if (start == -1 || S[start] < S[next])
            ret = max(ret, lis(next) + 1);
    return ret;
}

int count(int start) {
    if (lis(start) == 1) return 1;
    int &ret = cacheCnt[start];
    if (ret != -1) return ret;
    ret = 0;
    for (int next = start + 1; next <= n; ++next) {
        if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
            ret = min(MAX, ret + count(next));
    }
    return ret;
}

void reconstruct(int start, int skip, vector<int> &arr) {
    arr.push_back(S[start]);
    vector<pair<int,int>> followers;
    for (int next = start+1; next <= n; ++next)
        if ((start == 0 || S[start] < S[next]) && lis(start) == lis(next) + 1)
            followers.push_back({S[next], next});
    sort(followers.begin(), followers.end());
    for (int i = 0; i < followers.size(); ++i) {
        int idx = followers[i].second;
        int cnt = count(idx);
        if (cnt <= skip)
            skip -= cnt;
        else {
            reconstruct(idx, skip, arr);
            break;
        }
    }
}

#undef int
int main() {
#define int long long
    S[0] = -1e18;
    cin >> c;
    while (c--) {
        memset(cacheLen, -1, sizeof(cacheLen));
        memset(cacheCnt, -1, sizeof(cacheCnt));
        cin >> n >> k;
        for (int i=1;i<=n;++i)
            cin >> S[i];
        vector<int> a;
        reconstruct(0, k-1, a);
        cout << a.size()-1 << '\n';
        for (int i=1; i < a.size(); ++i)
            cout << a[i] << ' ';
        cout << '\n';
    }
}
