#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a, a+N);
    for (int i=0;i<N;++i) printf("%d ", a[i]);
}