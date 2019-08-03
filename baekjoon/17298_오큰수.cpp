#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main() {
    int N, x;
    scanf("%d", &N);
    stack<pair<int,int>> st;
    for (int i=0;i<N;++i) {
        scanf("%d", &x);
        while (!st.empty() && x > st.top().first) {
            a[st.top().second] = x;
            st.pop();
        }
        st.push({x, i});
    }
    while (!st.empty()) {
        a[st.top().second] = -1;
        st.pop();
    }
    for (int i=0;i<N;++i) printf("%d ", a[i]);
}