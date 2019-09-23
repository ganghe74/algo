#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, S, x, sum=0, ans = 1e7;;
    scanf("%d%d", &N, &S);
    queue<int> q;
    while (N--) {
        scanf("%d", &x);
        sum += x;
        q.push(x);
        while (sum - q.front() >= S) {
            sum -= q.front();
            q.pop();
        }
        if (sum >= S) ans = min(ans, int(q.size()));
    }
    if (ans == 1e7) ans = 0;
    printf("%d", ans);
}