#include <iostream>
using namespace std;

int a[30001], one[30001], two[30001];
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    one[0] = (a[0]==1)?0:1;
    for (int i=1;i<N;++i) {
        one[i] = one[i-1];
        if (a[i] == 2) one[i]++;
    }
    for (int i=N-1;i>=0;--i) {
        two[i] = two[i+1];
        if (a[i] == 1) two[i]++;
    }
    int ans = two[0];
    for (int i=0;i<N;++i) {
        ans = min(ans, one[i] + two[i+1]);
    }
    printf("%d", ans);
}