#include <bits/stdc++.h>
using namespace std;

int main() {
    int before = -1e9, now;
    while (scanf("%d", &now) != EOF) {
        if (before > now) {
            puts("Bad");
            return 0;
        }
        before = now;
    }
    puts("Good");
}