#include <bits/stdc++.h>
using namespace std;
int main() {
    int cnt = 0;
    char x;
    while ((x = getchar()) != EOF) {
        if (x == '\n') cnt++;
    }
    printf("%d", cnt);
}