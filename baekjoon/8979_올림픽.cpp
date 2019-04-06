#include <iostream>
using namespace std;

struct medal {
    int gold, silver, bronze;
};

int main() {
    medal a[1001];
    int N, K, n, g, s, b, cnt = 0;
    scanf("%d%d", &N, &K);
    for (int i=0;i<N;++i) {
        scanf("%d%d%d%d", &n, &g, &s, &b);
        a[n] = {g,s,b};
    }
    for (int i=1;i<=N;++i) {
        if (a[K].gold < a[i].gold) cnt++;
        else if (a[K].gold == a[i].gold) {
            if (a[K].silver < a[i].silver) cnt++;
            else if (a[K].silver == a[i].silver) {
                if (a[K].bronze < a[i].bronze) cnt++;
            }
        }
    }
    printf("%d", cnt+1);
}