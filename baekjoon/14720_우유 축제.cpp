#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, sell, cnt = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &sell);
        if (sell == cnt % 3) cnt++;
    }
    printf("%d", cnt);
}