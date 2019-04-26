#include <iostream>
using namespace std;
int main() {
    int a[10];
    int n, idx = 0;
    char s[200005];
    scanf("%d\n%s", &n, s);
    for (int i=1;i<10;++i) {
        scanf("%d", &a[i]);
    }

    while (a[s[idx]-'0'] <= s[idx]-'0' && idx < n) idx++;
    int start = idx;
    while (a[s[idx]-'0'] >= s[idx]-'0' && idx < n) idx++;

    for (int i=0;i<start;++i) putchar(s[i]);
    for (int i=start;i<idx;++i) putchar(a[s[i]-'0']+'0');
    for (int i=idx;i<n;++i) putchar(s[i]);
}