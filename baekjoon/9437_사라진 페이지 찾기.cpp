#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, P;
    while (true) {
        scanf("%d", &N);
        if (!N) break;
        scanf("%d", &P);
        int a[3];
        if (P % 2) a[0] = P+1;
        else a[0] = P-1;
        a[1] = N+1-P;
        a[2] = N+1-a[0];
        sort(a, a+3);
        for (int x : a) printf("%d ", x);
        puts("");
    }
}
