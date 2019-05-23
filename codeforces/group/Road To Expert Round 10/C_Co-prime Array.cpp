#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int n, before, now;
    vector<int> ans;
    scanf("%d", &n);
    scanf("%d", &before);
    for (int i=1;i<n;++i) {
        scanf("%d", &now);
        ans.push_back(before);
        if (gcd(before, now) != 1) ans.push_back(1);
        before = now;
    }
    ans.push_back(before);
    printf("%d\n", ans.size() - n);
    for (int x : ans) printf("%d ", x);
}