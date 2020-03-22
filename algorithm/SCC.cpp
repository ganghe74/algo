// https://www.acmicpc.net/problem/4013
#include <bits/stdc++.h>
using namespace std;

int N, M, S, P, u, v, cnt, atm[500001], satm[500001], dfsn[500001], sn[500001], ind[500001], d[500001];
bool finished[500001], hasRest[500001], shasRest[500001], reachable[500001];
vector<int> a[500001], sa[500001];
vector<vector<int>> scc;
stack<int> st;

// 여러가지 그래프프 다루다보니 실수하기가 쉽다.
// SCC DAG와 관련된 변수는 s 접미사를 붙이자.
// 그래프를 다룰때 항상 같은 그래프의 값을 비교하고 추가하는지 확인하자.
// (예를들어 if (sn[u] != sn[v]) 로 비교를 해놓고 sa[u].push_back(v) 를 한다던지..)

int dfs(int u) {
    int result = dfsn[u] = ++cnt;
    st.push(u);

    for (int v : a[u]) {
        if (!dfsn[v]) result = min(result, dfs(v));
        else if (!finished[v]) result = min(result, dfsn[v]);
    }

    if (dfsn[u] == result) {
        vector<int> currSCC;
        while (true) {
            int t = st.top(); st.pop();
            currSCC.push_back(t);
            sn[t] = scc.size();
            finished[t] = 1;
            satm[sn[t]] += atm[t];
            if (hasRest[t]) shasRest[sn[t]] = 1;
            if (t == u) break;
        }
        scc.push_back(currSCC);
    }
    return result;
}

int main() {
    scanf("%d%d", &N, &M);
    while (M--) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
    }
    for (int i=1;i<=N;++i) scanf("%d", atm+i);
    scanf("%d%d", &S, &P);
    while (P--) {
        scanf("%d", &u);
        hasRest[u] = 1;
    }

    for (int i=1;i<=N;++i)
        if (!dfsn[i]) dfs(i);
    
    for (int u=1;u<=N;++u) {
        for (int v : a[u]) {
            if (sn[u] != sn[v]) ind[sn[v]]++, sa[sn[u]].push_back(sn[v]);
        }
    }
    queue<int> q;
    for (int i=0;i<scc.size();++i) {
        d[i] = satm[i];
        if (!ind[i]) q.push(i);
    }
    reachable[sn[S]] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : sa[u]) {
            if (reachable[u]) {
                reachable[v] = 1;
                d[v] = max(d[v], d[u]+satm[v]);
            }
            if (--ind[v] == 0) q.push(v);
        }
    }

    int ans = 0;
    for (int i=0;i<scc.size();++i)
        if (shasRest[i] && reachable[i]) ans = max(ans, d[i]);
    printf("%d", ans);
}
