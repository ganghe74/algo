#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> a[500001];
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i].first), a[i].second = i;
    sort(a, a+n);
    for (int i=0;i<n;++i) ans = max(ans, a[i].second - i);
    printf("%d", ans+1);
}