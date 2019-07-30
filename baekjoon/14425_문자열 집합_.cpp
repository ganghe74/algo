#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    unordered_set<string> st;
    string s;
    int N, M, cnt=0;
    cin >> N >> M;
    while (N--) {
        cin >> s;
        st.insert(s);
    }
    while (M--) {
        cin >> s;
        if (st.find(s) != st.end()) cnt++;
    }
    cout << cnt;
}