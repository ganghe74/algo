#include <cstdio>
int main() {
    int cnt = 0;
    char x;
    while ((x = getchar()) != '#') {
        if (x == '\n') {
            printf("%d\n", cnt);
            cnt = 0;
        }
        if ('A' <= x && x <= 'Z') x += 32;
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') cnt++;
    }
}