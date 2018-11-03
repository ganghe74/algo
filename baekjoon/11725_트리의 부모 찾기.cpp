#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    vector<int> a[N+1];
    for (int i=1;i<N;++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int depth[N+1] = {0};
    int parent[N+1] = {0};
    int check[N+1] = {0};
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int now = q.front();
        check[now] = 1;
        q.pop();
        for (auto next : a[now]) {
            if (check[next] == 0) {
                depth[next] = depth[now] + 1;
                parent[next] = now;
                q.push(next);
            }
        }
    }
    for (int i=2;i<=N;++i) {
        printf("%d\n", parent[i]);
    }
}