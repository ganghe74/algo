#include <bits/stdc++.h>
using namespace std;
struct cmp {
    bool operator()(const int& a, const int& b) {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};
int main() {
    int N, x;
    priority_queue<int,vector<int>,cmp> pq;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &x);
        if (x == 0) {
            if (pq.empty()) puts("0");
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else pq.push(x);
    }
}