#include <iostream>
#include <cstring>
using namespace std;
int a[100001];
int check[100001];
int check_dfs[100001];

int dfs(int x, int cnt, int cnt_dfs) {
    check[x] = cnt;
    check_dfs[x] = cnt_dfs;
    int next = a[x];
    if (check[next] == 0) {
        return dfs(next, cnt+1, cnt_dfs);
    }
    else if (check_dfs[x] == check_dfs[next]) {
        return check[x] - check[next] + 1;
    }
    else return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, INSSA = 0;
        cin >> n;
        for (int i=1;i<=n;++i) {
            cin >> a[i];
        }
        int cnt_dfs = 1;
        for (int i=1;i<=n;++i) {
            if (check[i] == 0) {
                INSSA += dfs(i, 1, i);
            }
        }
        cout << n - INSSA << endl;
        memset(a, 0, sizeof(a));
        memset(check, 0, sizeof(check));
        memset(check_dfs, 0, sizeof(check_dfs));
    }
}