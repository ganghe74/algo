#include <bits/stdc++.h>
using namespace std;
vector<int> a[101];
bool check[101];
int main() {
    int N, M, cnt = -1;
    scanf("%d%d", &N, &M);
    while (M--) {
        int from, to;
        scanf("%d%d", &from, &to);
        a[from].push_back(to);
        a[to].push_back(from);
    }
    queue<int> Q;
    Q.push(1);
    check[1] = true;
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        ++cnt;
        for (int x : a[now]) {
            if (!check[x]) {
                Q.push(x);
                check[x] = true;
            }
        }
    }
    printf("%d", cnt);
}