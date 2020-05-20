#include <bits/stdc++.h>
using namespace std;

int d[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    int n;
    scanf("%d", &n);
    for (int h=0;h<24;++h) {
        for (int m=0;m<60;++m) {
            int cnt = 0;
            cnt += d[h / 10];
            cnt += d[h % 10];
            cnt += d[m / 10];
            cnt += d[m % 10];
            if (cnt == n) {
                printf("%02d:%02d", h, m);
                return 0;
            }
        }
    }
    puts("Impossible");
}
