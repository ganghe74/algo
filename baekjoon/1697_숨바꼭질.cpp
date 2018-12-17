#include <iostream>
#include <queue>
#define MAX 200000
using namespace std;
bool check[MAX];
int dist[MAX];
int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    queue<int> q;
    q.push(N);
    check[N] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : {now-1, now+1, now*2}) {
            if (0 <= next && next < MAX) {
                if (!check[next]) {
                    q.push(next);
                    check[next] = true;
                    dist[next] = dist[now] + 1;
                }
            }
        }
    }
    printf("%d", dist[K]);
}