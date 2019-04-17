#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
map<string, int> m;
vector<int> a[20];
int c[20];

void dfs(int now) {
    c[now] = 1;
    for (int next : a[now]) {
        if (!c[next]) dfs(next);
    }
}

int main() {
    string from[20], to[20];
    int N, t = 0;
    while (++t) {
        m.clear();
        for (int i=0;i<20;++i) a[i].clear(), c[i] = 0;
        cin >> N;
        if (N == 0) break;
        for (int i=0;i<N;++i) {
            cin >> from[i] >> to[i];
            m[from[i]] = i;
        }
        for (int i=0;i<N;++i) {
            a[m[from[i]]].push_back(m[to[i]]);
            a[m[to[i]]].push_back(m[from[i]]);
        }
        int cnt = 0;
        for (int i=0;i<N;++i) {
            if (!c[i]) {
                dfs(i);
                cnt++;
            }
        }
        cout << t << ' ' << cnt << endl;
    }
}