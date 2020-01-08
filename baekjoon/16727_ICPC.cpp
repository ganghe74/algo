#include <bits/stdc++.h>
using namespace std;

int main() {
    int s1, p1, s2, p2;
    scanf("%d%d", &p1, &s1);
    scanf("%d%d", &s2, &p2);
    if (s1 + s2 == p1 + p2) {
        if (s1 > p2) puts("Esteghlal");
        else if (s1 < p2) puts("Persepolis");
        else puts("Penalty");
    }
    else if (s1 + s2 > p1 + p2) puts("Esteghlal");
    else puts("Persepolis");
}