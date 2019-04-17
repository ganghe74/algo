#include <iostream>
#include <vector>
using namespace std;

struct edge {
    int to, w;
};

int N, robot1, robot2;
vector<edge> a[100001];
int c[100001];
vector<edge> path;

bool findPath(int now) {
    c[now] = true;
    if (now == robot2) return true;
    for (edge e : a[now]) {
        if (!c[e.to]) {
            path.push_back(e);
            if (findPath(e.to)) return true;
            path.pop_back();
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d", &N, &robot1, &robot2);
    for (int i=0;i<N-1;++i) {
        int v1, v2, w;
        scanf("%d%d%d", &v1, &v2, &w);
        a[v1].push_back({v2, w});
        a[v2].push_back({v1, w});
    }
    findPath(robot1);
    int sum = 0, maxW = 0;

    for (int i=1;i<=N;++i) {
        printf("vertex %d -> ", i);
        for (edge e : a[i]) printf("%d ", e.to);
        puts("");
    }

    printf("answer path : ");
    for (edge e : path) {
        printf("%d ", e.to);
    }
    puts("");

    for (edge e : path) {
        sum += e.w;
        maxW = max(maxW, e.w);
    }
    printf("%d", sum - maxW);
}