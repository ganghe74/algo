#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3];
    string s;
    cin >> a[0] >> a[1] >> a[2];
    cin >> s;
    sort(a, a+3);
    printf("%d %d %d\n", a[0], a[1], a[2]);
    for (auto x : s) cout << a[x-'A'] << ' ';
}