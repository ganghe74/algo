#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d", min({abs(a+b-c-d), abs(a+c-b-d), abs(a+d-b-c), abs(b+c-a-d), abs(b+d-a-c), abs(c+d-a-b)}));
}