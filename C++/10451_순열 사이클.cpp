#include <iostream>
#include <cstring>
using namespace std;
int a[1001] = {0};
bool check[1001] = {0};
void dfs(int x) {
    if (check[x]) return;
    check[x] = true;
    dfs(a[x]);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, answer = 0;
        cin >> N;
        for (int i=1;i<=N;++i) {
            cin >> a[i];
        }
        for (int i=1;i<=N;++i) {
            if(check[i] == false) {
                dfs(i);
                answer += 1;
            }
        }
        cout << answer << endl;
        memset(a,0,sizeof(a));
        memset(check,0,sizeof(check));
    }
}