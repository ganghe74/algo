#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> a, b;

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        scanf("%d", &x);
        a.push_back(x);
    }
    b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i=0;i<n;++i)
        printf("%d ", lower_bound(b.begin(), b.end(), a[i]) - b.begin());
}
