#include <bits/stdc++.h>
using namespace std;
bool c[100001];
int main() {
    for (int i=2;i<=100000;++i) {
        if (!c[i]) {
            for (int j=2;i*j<=100000;++j)
                c[i*j] = 1;
        }
    }
    int N, x;
    scanf("%d", &N);
    puts(c[N] ? "No" : "Yes");
}