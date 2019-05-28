#include <bits/stdc++.h>
using namespace std;
bool c[2000001];
vector<int> prime;
int main() {
    for (int i=2;i<=2000000;++i) {
        if (!c[i]) {
            prime.push_back(i);
            for (int j=2;i*j<=2000000;++j) c[i*j] = 1;
        }
    }
    int T, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &k);
        if (c[k]) {
            auto it = lower_bound(prime.begin(), prime.end(), k);
            printf("%d\n", *it - *(it-1));
        }
        else puts("0");
    }
}