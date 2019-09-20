#include <bits/stdc++.h>
using namespace std;
int N, M, x, y, d[100000];
vector<int> lis = {0};
vector<pair<int,int>> a;
int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d%d", &x, &y);
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    for (int i=0;i<N;++i) {
        if (lis.back() < a[i].second) {
            lis.push_back(a[i].second);
            d[i] = lis.size()-1;
        }
        else {
            auto it = lower_bound(lis.begin(), lis.end(), a[i].second);
            *it = a[i].second;
            d[i] = it - lis.begin();
        }
    }
    vector<int> ans;
    for (int i=N-1,len=lis.size()-1;i>=0;--i) {
        if (d[i] == len) len--;
        else ans.push_back(a[i].first);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d\n", x);
}