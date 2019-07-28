#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> a, p;
bool check() {
    vector<int> cnt(N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<i;++j) {
            if (p[i] < p[j]) cnt[p[i]]++;
        }
    }
    for (int i=0;i<N;++i) {
        if (a[i] != cnt[i]) return false;
    }
    return true;
}
int main() {
    scanf("%d", &N);
    a.resize(N); p.resize(N);
    for (int i=0;i<N;++i) {
        scanf("%d", &a[i]);
        p[i] = i;
    }

    do {
        if (check()) break;
    } while (next_permutation(p.begin(), p.end()));
    for (int i=0;i<N;++i) printf("%d ", p[i]+1);
}