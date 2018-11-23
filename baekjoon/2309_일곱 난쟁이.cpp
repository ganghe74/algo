#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[9];
    for (int i=0;i<9;++i) scanf("%d", &a[i]);
    int sum = 0;
    for (int i=0;i<9;++i) sum += a[i];
    for (int i=0;i<8;++i) {
        for (int j=i+1;j<9;++j) {
            if (sum - a[i] - a[j] == 100) {
                a[i] = -1;
                a[j] = -1;
                sort(a, a+9);
                for (int k=2;k<9;++k) printf("%d\n", a[k]);
                return 0;
            }
        }
    }
}