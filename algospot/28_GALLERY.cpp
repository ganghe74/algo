#include <iostream>
#include <vector>
using namespace std;

int V;
vector<int> adj[1000];
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
int installed;

int dfs(int here) {
    visited[here] = true;
    int children[3] = {0,0,0};
    for (int i=0;i<adj[here].size();++i) {
        int there = adj[here][i];
        if (!visited[there])
            ++children[dfs(there)];
    }
    if (children[UNWATCHED]) {
        ++installed;
        return INSTALLED;
    }
    if (children[INSTALLED])
        return WATCHED;
    return UNWATCHED;
}

int installCamera() {
    installed = 0;
    visited = vector<bool>(V, false);
    for (int u=0;u<V;++u)
        if(!visited[u] && dfs(u) == UNWATCHED)
            ++installed;
    return installed;
}

int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        int G, H, a, b;
        scanf("%d%d", &G, &H);
        V = G;
        for (int i=0;i<1000;++i) adj[i].clear();
        for (int i=0;i<H;++i) {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        printf("%d\n", installCamera());
    }
}