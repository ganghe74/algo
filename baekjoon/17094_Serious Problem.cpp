#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt2 = 0, cnte = 0;
    char s[100001];
    scanf("%d %s", &n, s);
    for (int i=0;i<n;++i) {
        if (s[i] == '2') cnt2++;
        else cnte++;
    }
    if (cnt2 > cnte) puts("2");
    else if (cnte > cnt2) puts("e");
    else puts("yee");
}