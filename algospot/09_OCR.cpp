#include <bits/stdc++.h>
using namespace std;

int n, m, q, cnt;
int R[100];
double T[501][501];
double M[501][501];
int choice[102][502];
double cache[102][502];
unordered_map<string, int> dic;
string s;
double p;

double recognize(int segment, int previousMatch) {
    if (segment == n) return 0;
    double &ret = cache[segment][previousMatch];
    if (ret != 1.0) return ret;
    ret = -1e200;
    int &choose = choice[segment][previousMatch];
    for (int thisMatch = 1; thisMatch <= m; ++thisMatch) {
        double cand = T[previousMatch][thisMatch] + M[thisMatch][R[segment]] + recognize(segment+1, thisMatch);
        if (ret < cand) {
            ret = cand;
            choose = thisMatch;
        }
    }
    return ret;
}

string corpus[501];
string reconstruct(int segment, int previousMatch) {
    int choose = choice[segment][previousMatch];
    string ret = corpus[choose];
    if (segment < n-1)
        ret = ret + " " + reconstruct(segment+1, choose);
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> m >> q;
    for (int i=1;i<=m;++i) {
        cin >> corpus[i];
        dic[corpus[i]] = ++cnt;
    }
    for (int i=1;i<=m;++i) {
        cin >> p;
        T[0][i] = log2(p);
    }
    for (int i=1;i<=m;++i) {
        for (int j=1;j<=m;++j) {
            cin >> p;
            T[i][j] = log2(p);
        }
    }
    for (int i=1;i<=m;++i) {
        for (int j=1;j<=m;++j) {
            cin >> p;
            M[i][j] = log2(p);
        }
    }

    while (q--) {
        cin >> n;
        for (int i=0;i<n;++i) {
            for (int j=0;j<=m;++j) {
                cache[i][j] = 1.0;
            }
        }
        for (int i=0;i<n;++i) {
            cin >> s;
            R[i] = dic[s];
        }
        recognize(0, 0);
        cout << reconstruct(0, 0) << '\n';
    }
}
