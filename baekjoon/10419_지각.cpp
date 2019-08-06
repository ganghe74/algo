#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, d;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &d);
        int i=0;
        while (i*i + i <= d) i++;
        printf("%d\n", i-1);
    }
}