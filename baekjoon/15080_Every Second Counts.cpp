#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, m, s;
    scanf("%d : %d : %d", &h, &m, &s);
    int begin = h * 3600 + m * 60 + s;
    scanf("%d : %d : %d", &h, &m, &s);
    int end = h * 3600 + m * 60 + s;
    if (begin > end) end += 86400;
    printf("%d", end-begin);
}