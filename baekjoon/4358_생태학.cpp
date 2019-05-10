#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(4);
    cout << fixed;
    int total = 0;
    map<string, int> m;
    string s;
    while (true) {
        getline(cin, s);
        if (cin.eof()) break;
        m[s]++;
        total++;
    }
    for (auto p : m) cout << p.first << " " << (double)p.second / total * 100 << '\n';
}