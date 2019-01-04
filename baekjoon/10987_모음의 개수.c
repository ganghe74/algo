#include <stdio.h>
#include <string.h>
int main() {
    char s[101];
    scanf("%s", s);
    int answer = 0, n = strlen(s);
    for (int i=0;i<n;++i) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            answer++;
        }
    }
    printf("%d", answer);
}