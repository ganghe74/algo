#include <iostream>
#include <vector>
using namespace std;
int check[1001];
int answer = 0;
vector<int> a[1001];
bool dfs(int x) {
    if (check[x] == 1) return false;
    check[x] = 1;
    for (auto &n : a[x]) {
        if (check[n] == 0) dfs(n);
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    while (M--) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i=1;i<=N;++i) {
        if (dfs(i)) answer += 1;
    }
    cout << answer;
}