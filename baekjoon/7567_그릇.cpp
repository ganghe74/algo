#include <iostream>
using namespace std;
int main() {
    int len = 0;
    char s[52];
    scanf("%s", s+1);
    for (int i=1;s[i]!='\0';++i) {
        if (s[i] == s[i-1]) len += 5;
        else len += 10;
    }
    printf("%d", len);
}