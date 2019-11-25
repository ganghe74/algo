#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", abs((a-1)%4 - (b-1)%4) + abs((a-1)/4 - (b-1)/4));
}