#include <bits/stdc++.h>
using namespace std;

int N, S, num;
vector<int> a, b, sub;
long long ans;

void choice(int idx, int sum) {
    if (idx == a.size()) {
        sub.push_back(sum);
        return;
    }
    choice(idx+1, sum+a[idx]);
    choice(idx+1, sum);
}

int main() {
    scanf("%d%d", &N, &S);
    for (int i=0;i<N/2;++i) {
        scanf("%d", &num);
        a.push_back(num);
    }
    choice(0,0);
    b = sub;
    a.clear(); sub.clear();
    for (int i=N/2;i<N;++i) {
        scanf("%d", &num);
        a.push_back(num);
    }
    choice(0,0);
    a = sub;

    sort(b.begin(), b.end());
    for (int x : a) {
        auto range = equal_range(b.begin(), b.end(), S-x);
        ans += range.second - range.first;
    }
    if (S == 0) ans--;
    printf("%lld", ans);
}