#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int C;
        scanf("%d", &C);
        printf("%d %d %d %d\n", C / 25, C % 25 / 10, C % 25 % 10 / 5, C % 5);
    }    
}