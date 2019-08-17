#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int N, K;
vector<string> a;
bool c[15];
lint ans;

bool cmp(string a, string b) {
    for (int i=0;i<a.size();++i) {
        if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) return false;
    }
    return true;
}

void choice(int idx, int todo) {
    if (!todo) {
        vector<string> strs;
        for (int i=0;i<N;++i)
            if (c[i]) strs.push_back(a[i]);
        for (int i=0;i<N;++i) {
            for (int j=0;j<i;++j) {
                if ((c[i] ^ c[j]) && cmp(a[i], a[j])) return;
            }
        }
        lint cnt = 1;
        for (int i=0;i<strs[0].size();++i) {
            bool q = true;
            for (int j=0;j<K;++j) {
                if (strs[j][i] != '?') {
                    q = false;
                    break;
                }
            }
            if (q) cnt = (cnt * 26) % 1000003;
        }
        ans = (ans + cnt) % 1000003;
        return;
    }
    for (int i=idx;i<=N-todo;++i) {
        if (!c[i]) {
            c[i] = 1;
            choice(i+1, todo-1);
            c[i] = 0;
        }
    }
}

int main() {
    cin >> N >> K;
    a.resize(N);
    for (int i=0;i<N;++i) cin >> a[i];
    choice(0, K);
    cout << ans;
}