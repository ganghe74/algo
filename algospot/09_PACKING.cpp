#include <bits/stdc++.h>
using namespace std;

int c, n, w;
int volume[100], need[100];
int cache[1001][100];
string name[100];

int pack(int capacity, int item) {
    if (item == n) return 0;
    int &ret = cache[capacity][item];
    if (ret != -1) return ret;
    ret = pack(capacity, item + 1);
    if (capacity >= volume[item])
        ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
    return ret;
}

void reconstruct(int capacity, int item, vector<string> &picked) {
    if (item == n) return;
    if (pack(capacity, item) == pack(capacity, item + 1))
        reconstruct(capacity, item+1, picked);
    else {
        picked.push_back(name[item]);
        reconstruct(capacity - volume[item], item + 1, picked);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));
        cin >> n >> w;
        for (int i=0;i<n;++i)
            cin >> name[i] >> volume[i] >> need[i];

        vector<string> picked;
        int ans = pack(w, 0);
        reconstruct(w, 0, picked);

        cout << ans << ' ' << picked.size() << '\n';
        for (auto &s : picked)
            cout << s << '\n';
    }
}
