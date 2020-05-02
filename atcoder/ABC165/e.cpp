#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=0;i<m/2;++i)
        printf("%d %d\n", i+1, m-i);
    for (int i=0;i<(m+1)/2;++i)
        printf("%d %d\n", m+i+1, m+m-i+1);
}
