#include <iostream>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int s;
        scanf("%d", &s);
        int n;
        scanf("%d", &n);
        for (int i=0;i<n;++i) {
            int q, p;
            scanf("%d %d", &q, &p);
            s += q * p;
        }
        printf("%d\n", s);
    }
}