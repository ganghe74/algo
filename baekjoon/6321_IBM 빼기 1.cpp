#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;++i) {
        char s[51];
        scanf("%s", s);
        printf("String #%d\n", i);
        for (int i=0;s[i]!='\0';++i) {
            if (s[i] == 'Z') printf("A");
            else printf("%c", s[i]+1);
        }
        printf("\n\n");
    }
}