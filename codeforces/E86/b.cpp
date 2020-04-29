#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    string t;
    cin >> T;
    while (T--) {
        cin >> t;
        int cnt0 = 0;
        int cnt1 = 0;
        for (char x : t) {
            if (x == '0') cnt0++;
            if (x == '1') cnt1++;
        }
        if (cnt0 == 0 || cnt1 == 0) cout << t << '\n';
        else {
            for (int i=0;i<t.size();++i) cout << "10";
            cout << '\n';
        }
    }
}
