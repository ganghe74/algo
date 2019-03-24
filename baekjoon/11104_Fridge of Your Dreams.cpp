#include <iostream>
using namespace std;
int main() {
    char bin[24];
    int n;
    scanf("%d", &n);
    while (n--) {
        int ans = 0;
        scanf("%s", bin);
        for (int i=0;i<24;++i) ans = ans * 2 + bin[i]-'0';
        printf("%d\n", ans);
    }
}