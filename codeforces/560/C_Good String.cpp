#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[200001];
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    bool odd = true;
    int i = 0, k = 0;
    while (i < n) {
        if (odd) {
            odd = !odd;
            if (i+1 < n && s[i] == s[i+1]) {
                int idx = i+1;
                while (idx < n && s[i] == s[idx]) {
                    s[idx] = '\0';
                    idx++; k++;
                }
                i = idx;
            }
            else {
                ++i;
            }
        }
        else {
            odd = !odd;
            i++;
        }
    }
    odd = !odd;
    if (odd) {
        int idx = n-1;
        while (s[idx] == '\0' && idx >= 0) idx--;
        s[idx] = '\0';
        k++;
    }

    printf("%d\n", k);
    for (int i=0;i<n;++i) {
        if (s[i] != '\0') putchar(s[i]);
    }
}