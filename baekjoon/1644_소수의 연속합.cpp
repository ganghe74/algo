#include <bits/stdc++.h>
using namespace std;
bool c[4000001];
vector<int> p;
int main() {
    for (int i=2;i<=4000000;++i) {
        if (!c[i]) {
            p.push_back(i);
            for (int j=2;j*i<=4000000;++j) c[i*j] = 1;
        }
    }
    int N, sum = 0, ans = 0;
    scanf("%d", &N);
    queue<int> q;
    for (int i=0;i<p.size();++i) {
        q.push(p[i]);
        sum += p[i];
        while (sum - q.front() >= N) {
            sum -= q.front();
            q.pop();
        }
        if (sum == N) ans++;
    }
    printf("%d", ans);
}