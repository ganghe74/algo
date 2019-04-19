#include <iostream>
using namespace std;
int main() {
    int N, K, tmp, cnt = 0;
    scanf("%d%d", &N, &K);
    for (int i=0;i<K;++i) {
        scanf("%d", &tmp);
        cnt += (tmp + 1) / 2;
    }
    if (cnt >= N) printf("YES");
    else printf("NO");
}