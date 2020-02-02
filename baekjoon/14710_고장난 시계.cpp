#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    puts(((a % 30) * 12 == b) ? "O" : "X");
}
