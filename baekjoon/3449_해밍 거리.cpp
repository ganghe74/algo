#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    char s1[101], s2[101];
    scanf("%d", &T);
    while (T--) {
        scanf("%s %s", s1, s2);
        int d = 0;
        for (int i=0;s1[i]!='\0';++i) {
            if (s1[i] != s2[i]) d++;
        }
        printf("Hamming distance is %d.\n", d);
    }
}