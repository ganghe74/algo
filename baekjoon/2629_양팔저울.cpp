#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, w;
    scanf("%d", &N);
    set<int> s;
    while (N--) {
        scanf("%d", &w);
        set<int> next;
        next.insert(w);
        for (int x : s) {
            next.insert(x);
            next.insert(abs(x-w));
            if (x+w <= 40000) next.insert(x+w);
        }
        s = next;
    }
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &w);
        if (s.find(w) != s.end()) printf("Y ");
        else printf("N ");
    }
}