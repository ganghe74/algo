#include <bits/stdc++.h>
using namespace std;

int N, K;
unordered_map<string, int> d;
string ori, dst;

int main() {
    cin >> N >> K;
    for (int i=1;i<=N;++i) {
        char x;
        cin >> x;
        ori += x;
        dst += to_string(i);
    }
    queue<string> q;
    q.push(ori);
    d[ori] = 1;
    while (!q.empty()) {
        string s = q.front(); q.pop();
        int dist = d[s];
        for (int i=0;i<=N-K;++i) {
            reverse(s.begin() + i, s.begin() + i + K);
            if (!d[s]) {
                q.push(s);
                d[s] = dist + 1;
            }
            reverse(s.begin() + i, s.begin() + i + K);
        }
    }
    cout << d[dst] - 1;
}
