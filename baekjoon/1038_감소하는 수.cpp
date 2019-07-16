#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
vector<lint> a;
bool c[10];
void make(int idx) {
    if (idx == 10) {
        lint x = 0;
        for (int i=9;i>=0;--i) {
            if (c[i]) {
                x *= 10;
                x += i;
            }
        }
        a.push_back(x);
        return;
    }
    c[idx] = 0;
    make(idx+1);
    c[idx] = 1;
    make(idx+1);
}
int main() {
    make(0);
    sort(a.begin(), a.end());
    int N;
    scanf("%d", &N);
    if (N >= 1023) puts("-1");
    else printf("%lld", a[N+1]);
}