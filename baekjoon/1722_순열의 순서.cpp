#include <iostream>
#include <vector>
using namespace std;
long long f[21] = {1};
bool c[21];
int main() {
    for (int i=1;i<=20;++i) f[i] = f[i-1] * i;
    int N, problem;
    scanf("%d%d", &N, &problem);
    if (problem == 1) {
        long long k;
        scanf("%lld", &k);
        vector<int> a(N);
        for (int i=0;i<N;++i) {
            for (int j=1;j<=N;++j) {
                if (c[j] == true) continue;
                if (f[N-i-1] < k) {
                    k -= f[N-i-1];
                }
                else {
                    a[i] = j;
                    c[j] = true;
                    break;
                }
            }
        }
        for (int i=0;i<N;++i) printf("%d ", a[i]);
    }
    else if (problem == 2) {
        vector<int> a(N);
        for (int i=0;i<N;++i) scanf("%d", &a[i]);
        long long ans = 0;
        for (int i=0;i<N;++i) {
            for (int j=1;j<a[i];++j) {
                if (c[j] == false) {
                    ans += f[N-i-1];
                }
            }
            c[a[i]] = true;
        }
        printf("%lld", ans+1);
    }
}