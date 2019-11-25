#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, N, A, B, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        vector<int> p(N+1);
        while (--N) {
            scanf("%d%d", &A, &B);
            p[B] = A;
        }
        stack<int> st1, st2;
        st1.push(-1); st2.push(-2);
        scanf("%d%d", &A, &B);
        while (A) {
            st1.push(A);
            A = p[A];
        }
        while (B) {
            st2.push(B);
            B = p[B];
        }
        while (st1.top() == st2.top()) {
            ans = st1.top();
            st1.pop(); st2.pop();
        }
        printf("%d\n", ans);
    }
}