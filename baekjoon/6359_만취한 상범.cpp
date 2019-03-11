#include <iostream>
using namespace std;
int main() {
    bool a[101] = {};
    int d[101] = {};
    for (int i=1;i<=100;++i) {
        for (int j=i;j<=100;j+=i) {
            a[j] = !a[j];
        }
        for (int j=1;j<=i;++j) {
            if (a[j]) d[i]++;
        }
    }
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
}