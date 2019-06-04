#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[11];
    scanf("%s", &s);
    int n = strlen(s);
    for (int i=1;i<n;++i) {
        int a = 1;
        int b = 1;
        for (int j=0;j<i;++j) a *= s[j] - '0';
        for (int j=i;j<n;++j) b *= s[j] - '0';
        if (a == b) {
            puts("YES");
            return 0;
        }
    } 
    puts("NO"); 
}