#include <bits/stdc++.h>
using namespace std;

int K, M, num, divisor = 1;
vector<int> a[10000001];

void choice(int d) {
    if (d == M-1) {
        for (int i=0;i<K;++i)
            a[num].push_back(num%divisor*K + i);
        return;
    }
    for (int i=0;i<K;++i) {
        num = num * K + i;
        choice(d+1);
        num /= K;
    }
}

int main() {
    scanf("%d%d", &K, &M);
    for (int i=0;i<M-2;++i) divisor *= K;
    choice(0);
    stack<int> st;
    st.push(0);
    while (!st.empty()) {
        int u = st.top();
        if (a[u].empty()) st.pop();
        else {
            int v = a[u].back();
            a[u].pop_back();
            st.push(v);
            printf("%d ", v % K);
        }
    }
}
