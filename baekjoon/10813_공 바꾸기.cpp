#include <iostream>
using namespace std;
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int ball[N+1];
    for (int i=1;i<=N;++i) ball[i] = i;
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        swap(ball[a], ball[b]);
    }
    for (int i=1;i<=N;++i) printf("%d ", ball[i]);
}