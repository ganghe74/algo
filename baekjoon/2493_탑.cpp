#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, h;
    scanf("%d", &N);
    stack<pair<int,int>> st;
    for (int i=1;i<=N;++i) {
        scanf("%d", &h);
        while (!st.empty() && st.top().first <= h) st.pop();
        printf("%d ", st.empty() ? 0 : st.top().second);
        st.push({h, i});
    }
}