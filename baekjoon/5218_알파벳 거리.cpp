#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    char s1[21], s2[21];
    scanf("%d", &T);
    while (T--) {
        scanf("%s %s", s1, s2);
        printf("Distances:");
        for (int i=0;s1[i]!='\0';++i) printf(" %d", (s2[i]-s1[i]+26)%26);
        puts("");
    }
}