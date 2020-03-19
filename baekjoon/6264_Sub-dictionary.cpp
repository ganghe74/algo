#include <bits/stdc++.h>
using namespace std;

int n, V, u, v, cnt, dfsn[2000], sn[2000], sind[2000];
bool finished[2000], dichas[2000];
vector<vector<int>> a, sa, scc, defis;
stack<int> st;
string s;
unordered_map<string, int> s2v;
unordered_map<int, string> v2s;

int dfs(int u) {
    int result = dfsn[u] = ++cnt;
    st.push(u);
    for (int v : a[u]) {
        if (!dfsn[v]) result = min(result, dfs(v));
        else if (!finished[v]) result = min(result, dfsn[v]);
    }
    if (dfsn[u] == result) {
        vector<int> currSCC;
        while (true) {
            int t = st.top(); st.pop();
            currSCC.push_back(t);
            finished[t] = 1;
            sn[t] = scc.size();
            if (t == u) break;
        }
        scc.push_back(currSCC);
    }
    return result;
}

void dicadd(int u) {
    if (dichas[u]) return;
    dichas[u] = 1;
    for (int v : defis[u]) dicadd(v);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (true) {
        cin >> n;
        if (!n) break;
        V = cnt = 0;
        scc.clear();
        s2v.clear(); v2s.clear();
        a.clear(); a.resize(2000);
        sa.clear(); sa.resize(2000);
        defis.clear(); defis.resize(2000);
        memset(dfsn, 0, sizeof(dfsn));
        memset(finished, 0, sizeof(finished));
        memset(sind, 0, sizeof(sind));
        memset(dichas, 0, sizeof(dichas));

        cin.ignore();
        while (n--) {
            string line, word, defi;
            getline(cin, line);
            stringstream ss(line);
            ss >> word;
            if (!s2v[word]) {
                s2v[word] = ++V;
                v2s[V] = word;
            }
            v = s2v[word];
            while (ss >> defi) {
                if (!s2v[defi]) {
                    s2v[defi] = ++V;
                    v2s[V] = defi;
                }
                u = s2v[defi];
                a[u].push_back(v);
                defis[v].push_back(u);
            }
        }

        
        for (int i=1;i<=V;++i)
            if (!dfsn[i]) dfs(i);
        for (int u=1;u<=V;++u) {
            for (int v : a[u]) {
                if (sn[u] != sn[v]) {
                    sa[sn[u]].push_back(sn[v]);
                    sind[sn[v]]++;
                }
            }
        }
        queue<int> q;
        for (int i=0;i<scc.size();++i)
            if (!sind[i]) {
                for (int u : scc[i]) dicadd(u);
                q.push(i);
                
            }

        while (!q.empty()) {
            int su = q.front(); q.pop();
            if (scc[su].size() > 1)
                for (int u : scc[su]) dicadd(u);
            for (int sv : sa[su]) {
                if (--sind[sv] == 0) q.push(sv);
            }
        }

        vector<string> ans;
        for (int i=1;i<=V;++i)
            if (dichas[i]) ans.push_back(v2s[i]);
        sort(ans.begin(), ans.end());

        cout << ans.size() << '\n';
        for (auto &s : ans) cout << s << ' ';
        cout << '\n';


        // DEBUG MESG
        // puts("=====VERTEX INFO=====");
        // for (auto pi : s2v) printf("%s %d\n", pi.first.c_str(), pi.second);
        // puts("=====SCC INFO=====");
        // for (auto &v : scc) {
            // for (int x : v) printf("%d " ,x);
            // puts("");
        // }
        // puts("================");
    }
}
