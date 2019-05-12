#include <bits/stdc++.h>
using namespace std;

bool c[500001];
double water[500001];
vector<int> a[500001];

int main() {
    int N, W;
    scanf("%d%d", &N, &W);
    for (int i=0;i<N-1;++i) {
        int U, V;
        scanf("%d%d", &U, &V);
        a[U].push_back(V);
        a[V].push_back(U);
    }
    water[1] = W;
    queue<int> q;
    q.push(1);
    c[1] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        int cnt = 0;
        for (int i=0;i<a[now].size();++i) {
            if (!c[a[now][i]]) cnt++;
        }
        if (cnt == 0) continue;
        double w = water[now] / cnt;
        water[now] = 0;
        for (int i=0;i<a[now].size();++i) {
            if (!c[a[now][i]]) {
                int next = a[now][i];
                water[next] = w;
                q.push(next);
                c[next] = 1;
            }
        }
    }
    int cnt = 0;
    double sum = 0;
    for (int i=1;i<=N;++i) {
        if (water[i] > 0) {
            cnt++;
            sum += water[i];
        }
    }
    printf("%f", sum / cnt);
}