#include <iostream>
using namespace std;
int main() {
    int d[10102];
    for (int k=0;k*k+k+1<=10101;++k) d[k*k+k+1] = k;
    int N;
    scanf("%d", &N);
    printf("%d", d[N]);
}