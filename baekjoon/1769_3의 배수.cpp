#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n = 0, cnt = 0;
    char s[1000001];
    scanf("%s", s);
    for (int i=0;s[i]!='\0';++i) n += s[i] - '0';
    if (strlen(s) > 1) cnt++;
    while (n >= 10) {
        cnt++;
        int next = 0;
        while (n > 0) {
            next += n % 10;
            n /= 10;
        }
        n = next;
    }
    printf("%d\n", cnt);
    puts((n % 3 == 0) ? "YES" : "NO");
}