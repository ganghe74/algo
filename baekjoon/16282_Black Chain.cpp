#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int main() {
    lint n, cut=1;
    cin >> n;
    while (true) {
        lint s = cut;
        for (int i=0;i<cut+1;++i) {
            s += s + 1;
        }
        if (n <= s) {
            cout << cut;
            return 0;
        }
        cut++;
    }
}