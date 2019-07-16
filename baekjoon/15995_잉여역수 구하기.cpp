#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, m, i=1;
    scanf("%d%d", &a, &m);
    while(a * i % m != 1) i++;
    printf("%d", i);
}