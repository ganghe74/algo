#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, cnt;
bool paint[100];
int main() {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    while (a < b) paint[a++] = 1;
    while (c < d) paint[c++] = 1;
    for (int i=0;i<100;++i)
        if (paint[i]) cnt++;
    printf("%d", cnt);
}
