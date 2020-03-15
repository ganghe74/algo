#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, M, n, mid;
    scanf("%d", &T);
    while (T--) {
        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;
        scanf("%d", &M);
        printf("%d\n", (M+1)/2);
        scanf("%d", &mid);
        printf("%d ", mid);
        for (int i=1;i<M;++i) {
            scanf("%d", &n);
            if (n < mid) maxheap.push(n);
            else minheap.push(n);
            if (minheap.size() + 1 < maxheap.size()) {
                minheap.push(mid);
                mid = maxheap.top();
                maxheap.pop();
            }
            if (minheap.size() > maxheap.size()) {
                maxheap.push(mid);
                mid = minheap.top();
                minheap.pop();
            }
            if (i % 20 == 0) puts("");
            if (i % 2 == 0) printf("%d ", mid);
        }
        puts("");
    }
}
