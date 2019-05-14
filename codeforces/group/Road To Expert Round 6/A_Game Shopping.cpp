#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, num, ans = 0;
    scanf("%d%d", &n, &m);
    queue<int> c, a;
    for (int i=0;i<n;++i) {
        scanf("%d", &num);
        c.push(num);
    }
    for (int i=0;i<m;++i) {
        scanf("%d", &num);
        a.push(num);
    }
    while (!c.empty() && !a.empty()) {
        int cost = c.front();
        int bill = a.front();
        if (bill >= cost) {
            a.pop();
            c.pop();
            ans++;
        }
        else c.pop();
    }
    printf("%d", ans);
}