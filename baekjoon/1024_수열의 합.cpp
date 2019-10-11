#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, L;
    scanf("%d%d", &N, &L);
    for (int len=L;len<=100;++len) {
        if ((len*len - len + 2*N) % (2*len) == 0) {
            int y = (len*len - len + 2*N) / (2*len);
            int x = y - len;
            if (x+1 < 0) break;
            for (int i=x+1;i<=y;++i) printf("%d ", i);
            return 0;
        }
    }
    puts("-1");
}