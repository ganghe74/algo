#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a, a+N);
    for (int i=0;i<N;++i) printf("%d\n", a[i]);
}