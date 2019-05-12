#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, L, M = 0;
        string S, M_S;
        cin >> N;
        while (N--) {
            cin >> S >> L;
            if (L > M) {
                M = L;
                M_S = S;
            }
        }
        cout << M_S << '\n';
    }
}