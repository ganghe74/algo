#include <iostream>
using namespace std;
int main() {
    int t, n;
    char s[101];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", s);
        int l = 0, r = n-1;
        while (s[l++] == '<' && s[r--] == '>');
        printf("%d\n", l-1);
    }
}