#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    if (T % 10 != 0) puts("-1");
    else printf("%d %d %d", T / 300, T % 300 / 60, T % 60 / 10);
}