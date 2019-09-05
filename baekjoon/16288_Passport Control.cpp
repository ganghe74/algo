#include <bits/stdc++.h>
using namespace std;
int a[100], N, K;
stack<int> st[100];

bool solve(int idx) {
    if (idx == N) return true;
    for (int i=0;i<K;++i) {
        if (!st[i].empty()) {
            if (a[idx] > st[i].top()) {
                st[i].push(a[idx]);
                if (solve(idx+1)) return true;
                st[i].pop();
                return false;
            }
        }
        else {
            st[i].push(a[idx]);
            if (solve(idx+1)) return true;
            st[i].pop();
            return false;
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    if (solve(0)) puts("YES");
    else puts("NO");
}