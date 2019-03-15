#include <iostream>
using namespace std;
int main() {
    char s[81];
    int T, skip;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s", &skip, s);
        for (int i=0;s[i]!='\0';++i) {
            if (i != skip-1) putchar(s[i]);
        }
        puts("");
    }
}