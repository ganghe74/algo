#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, x;
    string op;
    queue<int> q;
    cin >> N;
    while (N--) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            q.push(x);
        }
        else if (op == "pop") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (op == "size") cout << q.size() << '\n';
        else if (op == "empty") cout << q.empty() << '\n';
        else if (op == "front") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
}