#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        priority_queue<pair<int,int>> pq;
        pq.push({n, 0});
        int i = 1;
        while (!pq.empty()) {
            auto [len, begin] = pq.top(); pq.pop();
            begin = -begin;
            int mid = (begin + begin + len - 1) / 2;
            a[mid] = i++;
            if ((len-1)/2 > 0) pq.push({(len-1)/2, -begin});
            if (len/2 > 0) pq.push({len/2, -(mid+1)});
        }
        for (int x : a) printf("%d ", x);
        puts("");
    }
}
