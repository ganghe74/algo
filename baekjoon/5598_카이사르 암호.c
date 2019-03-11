#include <stdio.h>
int main() {
    char s[1001];
    gets(s);
    for (int i=0;s[i]!='\0';++i) {
        if (s[i] <= 'C') s[i] += 23;
        else s[i] -= 3;
    }
    puts(s);
}