#include <iostream>
using namespace std;
int d[5001] = {1};
int main() {
    int i;
    char s[5002];
    scanf("%s", s+1);
    for (i=1;s[i]!='\0';++i) {
        int x = (s[i-1]-'0')*10 + s[i]-'0';
        if (10 <= x && x <= 26) d[i] += d[i-2];
        if (s[i] != '0') d[i] += d[i-1];
        d[i] %= 1000000;
    }
    printf("%d", d[i-1]);
}