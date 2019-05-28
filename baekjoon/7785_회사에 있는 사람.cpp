#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    set<string> s;
    int n;
    cin >> n;
    while (n--) {
        string name, go;
        cin >> name >> go;
        if (go == "enter") {
            s.insert(name);
        }
        else {
            s.erase(name);
        }
    }
    for (auto it=s.rbegin();it!=s.rend();++it) {
        cout << *it << '\n';
    }
}