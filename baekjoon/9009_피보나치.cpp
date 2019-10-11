#include <bits/stdc++.h>
using namespace std;
int d[47] = {0, 1};
int main() {
    for (int i=2;i<47;++i) d[i]=d[i-1]+d[i-2]; // f47 = 1e9++
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        stack<int> st;
        for (int i=46;i>0;--i) {
            if (n >= d[i]) {
                st.push(d[i]);
                n -= d[i];
            }
        }
        while (!st.empty()) {
            printf("%d ", st.top());
            st.pop();
        }
        puts("");
    }
}