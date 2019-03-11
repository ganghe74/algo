#include <iostream>
using namespace std;
int main() {
    char s[101];
    scanf("%s", s);
    for (int i=0;s[i]!='\0';++i) {
        if ('A' <= s[i] && s[i] <= 'Z') s[i] +=32;
        else s[i] -= 32;
    }
    printf("%s", s);
}