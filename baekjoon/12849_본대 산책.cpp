#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int d[100000][8];

vector<int> a[] = {
    {1, 2},
    {0, 2, 3},
    {0, 1, 3, 4},
    {1, 2, 4, 5},
    {2, 3, 5, 7},
    {3, 4, 6},
    {5, 7},
    {4, 6}
};

int D;

int main() {
    d[0][0] = 1;
    scanf("%d", &D);
    for (int i=0;i<D;++i) {
        for (int u=0;u<8;++u) {
            for (int v : a[u]) {
                d[i+1][v] += d[i][u];
                d[i+1][v] %= mod;
            }
        }
    }
    printf("%d", d[D][0]);
}
