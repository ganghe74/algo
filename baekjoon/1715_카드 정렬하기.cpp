#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, x, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &x);
        pq.push(x);
    }
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a+b);
    }
    printf("%d", ans);
}