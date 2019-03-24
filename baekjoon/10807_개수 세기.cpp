#include <iostream>
using namespace std;
int main() {
    int a[100];
    int N, v, cnt = 0;
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    scanf("%d", &v);
    for (int i=0;i<N;++i)
        if (a[i] == v) cnt++;
    printf("%d", cnt);
}