#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a;

int main() {
    scanf("%d", &N);
    a.resize(N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());

    int i=0, j=N-1;
    vector<int> ans = {a[i], a[j]};
    int diff = abs(a[i]+a[j]);
    while (i < j) {
        if (abs(a[i]+a[j]) < diff) {
            ans = {a[i], a[j]};
            diff = abs(a[i]+a[j]);
        }
        if (a[i]+a[j] > 0) j--;
        else i++;
    }
    printf("%d %d", ans[0], ans[1]);
}
