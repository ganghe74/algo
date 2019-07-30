#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, x;
    scanf("%d", &N);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0;i<N;++i) {
        scanf("%d", &x);
        pq.push(x);
    }
    for (int i=1;i<N;++i) {
        for (int j=0;j<N;++j) {
            scanf("%d", &x);
            if (x > pq.top()) {
                pq.pop();
                pq.push(x);
            }
        }
    }
    printf("%d", pq.top());
}