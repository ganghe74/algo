#include <iostream>
using namespace std;
int main() {
    char s[21];
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", s);
        for (int i=0;s[i]!='\0';++i) {
            if (s[i] <= 'Z') putchar(s[i]+32);
            else putchar(s[i]);
        }
        puts("");
    }
}