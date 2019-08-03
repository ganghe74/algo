#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int a = 0, b = 0;
        char x, y;
        while (N--) {
            scanf(" %c %c", &x, &y);
            if (x == y) continue;
            else if ((x == 'R' && y == 'S') || (x == 'S' && y == 'P') || (x == 'P' && y == 'R')) a++;
            else b++;
        }
        if (a > b) puts("Player 1");
        else if (a < b) puts("Player 2");
        else puts("TIE");
    }
}