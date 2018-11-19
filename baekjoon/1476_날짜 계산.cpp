#include <bits/stdc++.h>
using namespace std;
int main() {
    int E, S, M, e, s, m, year;
    scanf("%d %d %d", &E, &S, &M);
    year = e = s = m = E;
    while (s != S || m != M) {
        s = s + 15;
        if (s > 28) s %= 28;
        m = m + 15;
        if (m > 19) m %= 19;
        year += 15;
    }
    printf("%d", year);
}