#include <bits/stdc++.h>
using namespace std;
int N, a, b, c;
char x;
int main() {
    scanf("%d ", &N);
    for (int i=0;i<N;++i) {
        scanf("%c", &x);
        if ("ABC"[i%3] == x) a++;
        if ("BABC"[i%4] == x) b++;
        if ("CCAABB"[i%6] == x) c++;
    }
    int M = max({a, b, c});
    printf("%d\n", M);
    if (a == M) puts("Adrian");
    if (b == M) puts("Bruno");
    if (c == M) puts("Goran");
}