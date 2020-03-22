#include <bits/stdc++.h>
using namespace std;

vector<int> a[100]; // adj list
int ind[100]; // indegree
int V, E, u, v; // # of vertex, edge. u, v for temp.

int main() {
    // input graph
    /*
    sample data
    5 5
    1 2
    1 3
    1 4
    3 4
    3 5
    */

    scanf("%d%d", &V, &E);
    while (E--) {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        ind[v]++;
    }

    // find start vertex (has indegree 0)
    queue<int> q;
    for (v=1;v<=V;++v) {
        if (!ind[v]) q.push(v);
    }

    // BFS
    while (!q.empty()) {
        int u = q.front(); q.pop();
        printf("%d ", u);
        for (int v : a[u]) {
            if (!--ind[v]) q.push(v);
        }
    }
}