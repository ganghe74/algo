#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, k, n;
    char c;
    scanf("%d", &T);
    while (T--) {
        multiset<int> s;
        scanf("%d", &k);
        while (k--) {
            scanf(" %c %d", &c, &n);
            if (c == 'I') s.insert(n);
            else {
                if (s.empty()) continue;
                if (n == 1) s.erase(--s.end());
                else s.erase(s.begin());
            }
        }
        if (s.empty()) puts("EMPTY");
        else printf("%d %d\n", *(--s.end()), *s.begin());
    }
}
