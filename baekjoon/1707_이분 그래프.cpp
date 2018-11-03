#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
char check[20001] = {0};
vector<int> a[20001];

bool dfs(int x, int c) {
    check[x] = c;
    for (auto &n : a[x]) {
        if (check[n] == 0) {
            if (dfs(n,3-c) == false) return false;
        }
        else if(check[x] == check[n]) return false;
    }
    return true;
}

int main() {
    int K;
    cin >> K;
    while (K--) {
        int V, E;
        cin >> V >> E;
        while (E--) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        bool YES = true;
        for (int i=1;i<=V;++i){
            if (check[i] == 0) {
                if (dfs(i,1) == false) YES = false;
            }
        }
        if (YES) cout << "YES" << endl;
        else cout << "NO" << endl;
        memset(check, 0, sizeof(check));
        memset(a, 0, sizeof(a));
    }
}