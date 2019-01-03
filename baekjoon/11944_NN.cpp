#include <iostream>
using namespace std;
int main() {
    int a[4] = {-1,-1,-1,-1};
    int N, M, i = 3, j = 4;
    scanf("%d%d", &N, &M);
    int n = N;
    while (n > 0) {
        a[i] = n % 10;
        n /= 10;
        i--;
    }
    while (M--) {
        if (j == 4) {
            j = i+1;
            if (N-- == 0) break;
        }
        printf("%d", a[j++]);
    }
}