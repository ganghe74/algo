#include <bits/stdc++.h>
using namespace std;

int N, M, num, x, ind[2000], outd[2000];
map<vector<int>, int> vertex;
map<int, vector<int>> v2arr;
vector<int> a[2000];
stack<int> st;

void euler(int u) {
    while (!a[u].empty()) {
        int v = a[u].back();
        a[u].pop_back();
        euler(v);
    }
    st.push(u);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0;i<N-M+1;++i) {
        vector<int> u, v;
        scanf("%d", &x);
        u.push_back(x);
        for (int i=0;i<M-2;++i) {
            scanf("%d", &x);
            u.push_back(x);
            v.push_back(x);
        }
        scanf("%d", &x);
        v.push_back(x);
        if (!vertex[u]) {
            vertex[u] = ++num;
            v2arr[num] = u;
        }
        if (!vertex[v]) {
            vertex[v] = ++num;
            v2arr[num] = v;
        }
        a[vertex[u]].push_back(vertex[v]);
        outd[vertex[u]]++;
        ind[vertex[v]]++;
    }
    int start = 1;
    for (int i=1;i<=num;++i) {
        if (outd[i] > ind[i]) {
            start = i;
            break;
        }
    }
    euler(start);
    x = st.top();
    for (int i=0;i<M-2;++i) printf("%d ", v2arr[x][i]);
    while (!st.empty()) {
        x = st.top(); st.pop();
        printf("%d ", v2arr[x][M-2]);
    }
}
