#include <iostream>
using namespace std;
int a[50], p[50];
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    for (int i=N-1;i>=0;--i) {
        int idx = 0;
        for (int j=0;j<N;++j) {
            if (a[idx] <= a[j]) idx = j;
        }
        p[idx] = i;
        a[idx] = 0;
    }
    for (int i=0;i<N;++i) printf("%d ", p[i]);
}