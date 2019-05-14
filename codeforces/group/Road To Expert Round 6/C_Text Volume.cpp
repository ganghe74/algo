#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, word = 0, text = 0;
    char x;
    scanf("%d ", &n);
    while (n--) {
        x = getchar();
        if ('A' <= x && x <= 'Z') {
            word++;
        }
        if (x == ' ') {
            text = max(text, word);
            word = 0;
        }
    }
    text = max(text, word);
    printf("%d", text);
}