#include <bits/stdc++.h>
using namespace std;

int main() {
    long long num = 0, sum = 0;
    char x;
    while ((x = getchar()) != EOF) {
        if (x == '\n') continue;
        if (x == ',') {
            sum += num;
            num = 0;
        }
        else {
            num = num * 10 + (x - '0');
        }
    }
    printf("%lld", sum + num);
}