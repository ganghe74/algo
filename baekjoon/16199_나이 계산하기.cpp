#include <bits/stdc++.h>
using namespace std;

int main() {
    int Y1, Y2, M1, M2, D1, D2;
    scanf("%d%d%d%d%d%d", &Y1, &M1, &D1, &Y2, &M2, &D2);
    if (M2 > M1 || (M2 == M1 && D2 >= D1)) printf("%d\n", Y2-Y1);
    else printf("%d\n", Y2-Y1-1);
    printf("%d\n", Y2 - Y1 + 1);
    printf("%d", Y2 - Y1);
}