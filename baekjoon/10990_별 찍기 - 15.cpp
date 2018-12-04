#include <iostream>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    for (int i=1;i<N;++i) printf(" ");
    printf("*\n");
    for (int i=2;i<=N;++i) {
        for (int j=0;j<N-i;++j) printf(" ");
        printf("*");
        for (int j=0;j<2*(i-1)-1;++j) printf(" ");
        printf("*\n");
    }
}