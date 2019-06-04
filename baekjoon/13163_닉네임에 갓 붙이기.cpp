#include <bits/stdc++.h>
using namespace std;
int main() {
    char x;
    int N;
    scanf("%d", &N);
    while (N--) {
        while ((x = getchar()) != ' ');
        printf("god");
        while ((x = getchar()) != '\n') {
            if (x == ' ') continue;
            putchar(x);
        }
        puts("");
    }
}