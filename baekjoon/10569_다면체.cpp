#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, V, E;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &V, &E);
        printf("%d\n", 2 - V + E);
    }
}