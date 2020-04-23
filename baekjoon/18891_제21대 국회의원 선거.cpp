#include <bits/stdc++.h>
using namespace std;
using lint = long long;

struct election {
    string name;
    int vote, r, s, t;
    double p;
    bool pr;
};

bool cmp(election &a, election &b) {
    int a_val = a.r + a.s + a.t;
    int b_val = b.r + b.s + b.t;
    if (a_val == b_val) return a.name < b.name;
    return a_val > b_val;
}

int P, V, R;
election e[50];
lint sum_votes, sum_votes_pr, sum_s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> P >> V;
    for (int i=0;i<P;++i) {
        cin >> e[i].name >> e[i].r >> e[i].vote;
        sum_votes += e[i].vote;
    }

    R = 253;
    for (int i=0;i<P;++i) {
        double rate = (double)e[i].vote / (double)sum_votes;
        e[i].pr = (rate >= 0.03) || (e[i].r >= 5);
        if (e[i].pr) {
            sum_votes_pr += e[i].vote;
            R -= e[i].r;
        }
    }
    for (int i=0;i<P;++i)
        if (e[i].pr)
            e[i].p = (double)e[i].vote / (double)sum_votes_pr;

    for (int i=0;i<P;++i) {
        if (e[i].pr) {
            double tmp = ((300 - R) * e[i].p - e[i].r) / 2.0;
            if (tmp < 1.0) e[i].s = 0;
            else e[i].s = round(tmp); // + 0.1
            sum_s += e[i].s;
        }
    }

    double s[50];
    if (sum_s < 30) {
        for (int i=0;i<P;++i)
            if (e[i].pr)
                s[i] = e[i].s + (30 - sum_s) * e[i].p;
    }
    else if (sum_s > 30) {
        for (int i=0;i<P;++i)
            if (e[i].pr)
                s[i] = (double)30 * e[i].s / sum_s;
    }
    sum_s = 0;
    for (int i=0;i<P;++i) {
        if (e[i].pr) {
            e[i].s = s[i];
            s[i] -= e[i].s;
            sum_s += e[i].s;
        }
    }
    while (sum_s < 30) {
        int max_idx = -1;
        for (int i=0;i<P;++i)
            if (e[i].pr && (max_idx == -1 || s[i] > s[max_idx])) max_idx = i;
        s[max_idx] = -1;
        sum_s++;
        e[max_idx].s++;
    }

    double t[50];
    for (int i=0;i<P;++i)
        if (e[i].pr)
            t[i] = 17 * e[i].p;
    lint sum_t = 0;
    for (int i=0;i<P;++i) {
        if (e[i].pr) {
            e[i].t = t[i];
            t[i] -= e[i].t;
            sum_t += e[i].t;
        }
    }
    while (sum_t < 17) {
        int max_idx = -1;
        for (int i=0;i<P;++i)
            if (e[i].pr && (max_idx == -1 || t[i] > t[max_idx])) max_idx = i;
        t[max_idx] = -1;
        sum_t++;
        e[max_idx].t++;
    }

    sort(e, e+P, cmp);

    for (int i=0;i<P;++i)
        cout << e[i].name << ' ' << e[i].r + e[i].s + e[i].t << '\n';
}
