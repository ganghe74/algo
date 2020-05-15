#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, x;
map<int, priority_queue<int>> m;


#undef int
int main() {
#define int long long

    scanf("%lld", &n);
    for (int i=0;i<n;++i) {
        scanf("%lld", &x);
        map<int,int> divisors;

        for (int i=2;i<sqrt(x)+5;++i) {
            while (x % i == 0) {
                divisors[i]++;
                x /= i;
            }
        }
        if (x != 1) divisors[x]++;
        for (auto [num, cnt] : divisors) {
            m[num].push(-cnt);
        }
    }

    int ans = 1;

    for (auto &[num, pq] : m) {
        int e;
        if (pq.size() == n) pq.pop();
        if (pq.size() != n-1) pq.push(0);
        e = -pq.top();
        while (e--)
            ans *= num;
    }
    printf("%lld", ans);
}
