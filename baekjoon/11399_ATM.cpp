#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, answer = 0, sum = 0;
    scanf("%d", &N);
    int a[N];
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a, a+N);
    for (int i=0;i<N;++i) {
        sum += a[i];
        answer += sum;
    }
    printf("%d", answer);
}