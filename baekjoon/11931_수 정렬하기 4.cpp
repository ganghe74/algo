#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> a(N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    for (int i=N-1;i>=0;--i) printf("%d\n", a[i]);
}