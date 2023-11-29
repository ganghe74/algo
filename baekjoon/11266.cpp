// 231129
#include <bits/stdc++.h>

using namespace std;

int V, E, u, v, cnt;
int back[10001], dfsn[10001], isCut[10001];
vector<int> adj[10001];

void BicompDFS(int u) {
    dfsn[u] = back[u] = ++cnt;
    stack<pair<int,int>> st;
    for (auto v : adj[u]) {
        if (dfsn[v] < dfsn[u]) {
            st.push({u, v});
        }
        if (!dfsn[v]) {
            BicompDFS(v);
            if (back[v] >= dfsn[u]) {
                auto [p, q] = st.top();
                isCut[p]++;
                while (1) {
                    auto [p, q] = st.top(); st.pop();
                    if (p == u && q == v) break;
                }
            }
            else {
                back[u] = min(back[u], back[v]);
            }
        }
        else {
            back[u] = min(back[u], dfsn[v]);
        }
    }
}

int main() {
    scanf("%d%d", &V, &E);
    while (E--) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 1 ; u <= V ; ++u) {
        if (!dfsn[u]) {
            BicompDFS(u);
            isCut[u]--;
        }
    }

    int cutcnt = 0;
    for (int u = 1; u <= V; ++u)
        if (isCut[u] > 0) cutcnt++;
    cout << cutcnt << '\n';
    for (int u = 1; u <= V; ++u)
        if (isCut[u] > 0) cout << u << ' ';
}