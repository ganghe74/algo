#include <bits/stdc++.h>
using namespace std;
int k;
char bracket[9];
vector<int> a(10), m, M;

bool check() {
    for (int i=0;i<k;++i) {
        if (bracket[i] == '<') {
            if (a[i] >= a[i+1]) return false;
        }
        else {
            if (a[i] <= a[i+1]) return false;
        }
    }
    return true;
}

int main() {
    for (int i=0;i<10;++i) a[i] = i;
    scanf("%d", &k);
    for (int i=0;i<k;++i) scanf(" %c", &bracket[i]);
    do {
        if (check()) {
            if (m.empty()) m = a;
            M = a;
        }
    } while (next_permutation(a.begin(), a.end()));
    for (int i=0;i<=k;++i) printf("%d", M[i]);
    puts("");
    for (int i=0;i<=k;++i) printf("%d", m[i]);
}