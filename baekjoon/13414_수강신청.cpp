#include <bits/stdc++.h>
using namespace std;

vector<bool> check(100000000,0);

int main() {
    int K, L, scan;
    vector<int> in;
    stack<int> s;
    scanf("%d %d", &K, &L);
    for (int i=0;i<L;++i) {
        scanf("%d", &scan);
        in.push_back(scan);
    }
    for (int i=L-1;i>=0;--i) {
        if (!check[in[i]]) {
            s.push(in[i]);
            check[in[i]] = true;
        }
    }
    for (int i=0;i<K;++i) {
        if (s.empty()) break;
        printf("%08d\n", s.top());
        s.pop();
    }
}