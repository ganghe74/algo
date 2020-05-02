#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> a;
        for (int i=1;i<=n;i*=2) {
            a.push_back(i);
            n -= i;
        }
        if (n > 0) {
            a.push_back(n);
            sort(a.begin(), a.end());
        }
        printf("%d\n", a.size()-1);
        for (int i=1;i<a.size();++i) printf("%d ", a[i]-a[i-1]);
        puts("");
    }
}
