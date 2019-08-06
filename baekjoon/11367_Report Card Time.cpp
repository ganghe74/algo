#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n;
    char s[11];
    scanf("%d ", &T);
    while (T--) {
        scanf("%s %d ", s, &n);
        printf("%s ", s);
        if (n >= 97) puts("A+");
        else if (n >= 90) puts("A");
        else if (n >= 87) puts("B+");
        else if (n >= 80) puts("B");
        else if (n >= 77) puts("C+");
        else if (n >= 70) puts("C");
        else if (n >= 67) puts("D+");
        else if (n >= 60) puts("D");
        else puts("F");
    }
}