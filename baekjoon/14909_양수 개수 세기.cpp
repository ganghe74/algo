#include <iostream>
using namespace std;
int main() {
    int n, ans = 0;
    while (scanf("%d", &n) != EOF) {
        if (n > 0) ans++;
    }
    printf("%d", ans);
}