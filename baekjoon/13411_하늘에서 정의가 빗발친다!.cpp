#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    vector<pair<double,int>> a;
    for (int i=1;i<=N;++i) {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        double t = sqrt(x*x + y*y) / v;
        a.push_back({t,i});
    }
    sort(a.begin(), a.end());
    for (auto pi : a) printf("%d\n", pi.second);
}