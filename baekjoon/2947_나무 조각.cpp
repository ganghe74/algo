#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[5];
    for (int i=0;i<5;++i) scanf("%d", &a[i]);
    while (a[0] != 1 || a[1] != 2 || a[2] != 3 || a[3] != 4 || a[4] != 5) {
        for (int i=0;i<4;++i) {
            if (a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
                for (int j=0;j<5;++j) printf("%d ", a[j]);
                puts("");
            }
        }
    }
}