#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, i, j;
    scanf("%d%d", &N, &M);
    vector<int> a(N);
    iota(a.begin(), a.end(), 1);
    while (M--) {
        scanf("%d%d", &i, &j);
        reverse(a.begin()+i-1, a.begin()+j);
    }
    for (int x : a) printf("%d ", x);
}