#include <bits/stdc++.h>
using namespace std;

int V, E, u, v, w, cnt, dfsn[10000], SN, sn[10000];
bool finished[10000];
vector<int> adj[10001];
stack<int> S;
vector<vector<int>> SCC;

int DFS(int curr) {
    dfsn[curr] = ++cnt;
    S.push(curr);

    int result = dfsn[curr];
    for (int next : adj[curr]) {
        if (dfsn[next] == 0) result = min(result, DFS(next));
        else if (!finished[next]) result = min(result, dfsn[next]);
    }

    if (result == dfsn[curr]) {
        vector<int> currSCC;
        while (true) { 
            int t = S.top();
            S.pop();
            currSCC.push_back(t);
            finished[t] = true;
            sn[t] = SN;
            if (t == curr) break;
        }
        sort(currSCC.begin(), currSCC.end());
        SCC.push_back(currSCC);
        SN++;
    }
    return result;
}

int main() {
    scanf("%d%d", &V, &E);
    while (E--) {
        scanf("%d%d", &u, &v);
        adj[u-1].push_back(v-1);
    }
    for (int i=0;i<V;++i)
        if (dfsn[i] == 0) DFS(i);
    sort(SCC.begin(), SCC.end());
    printf("%d\n", int(SCC.size()));
    for (auto v : SCC) {
        for (int x : v) printf("%d ", x+1);
        puts("-1");
    }
}
