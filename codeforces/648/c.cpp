#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    scanf("%d", &n);
    vector<int> pos(n+1), d(n);
    for (int i=0;i<n;++i) {
        scanf("%d", &x);
        pos[x] = i;
    }
    for (int i=0;i<n;++i) {
        scanf("%d", &x);
        int dist = pos[x] - i;
        if (dist < 0) dist += n;
        d[dist]++;
    }
    printf("%d", *max_element(d.begin(), d.end()));
}
