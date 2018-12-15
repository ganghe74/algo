#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
vector<pair<int,int>> a[10001];
bool c[10001];
int st, ed;
bool go(int node, int limit) {
    if (c[node]) return false;
    c[node] = true;
    if (node == ed) return true;
    for (auto p : a[node]) {
        int next = p.first;
        int cost = p.second;
        if (limit <= cost) {
            if (go(next, limit)) return true;
        }
    }
    return false;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    while (M--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(make_pair(y,z));
        a[y].push_back(make_pair(x,z));
    }
    scanf("%d%d", &st, &ed);
    int l = 0;
    int r = 1000000000;
    while (l <= r) {
        int mid = (l + r)/2;
        memset(c, 0, sizeof(c));
        if (go(st, mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d", r);
}