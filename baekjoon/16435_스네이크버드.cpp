#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, L, h;
    scanf("%d%d", &N, &L);
    priority_queue<int, vector<int>, greater<>> pq;
    while (N--) {
        scanf("%d", &h);
        pq.push(h);
    }
    while (!pq.empty()) {
        if (pq.top() > L) break;
        pq.pop();
        L++;
    }
    printf("%d", L);
}