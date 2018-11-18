#include <iostream>
using namespace std;
int main() {
    int M, N, sum = 0;
    scanf("%d\n%d", &M,&N);
    int i=0;
    for (;i*i<M;++i);
    for (int j=i;j*j<=N;++j) sum += j*j;
    if (sum == 0) printf("-1");
    else printf("%d\n%d",sum, i*i);
}