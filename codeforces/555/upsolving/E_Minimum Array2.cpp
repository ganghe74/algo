#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    int a[200005], b[200005];
    multiset<int> ms;
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    for (int i=0;i<n;++i) {
        scanf("%d", &b[i]);
        ms.insert(b[i]);
    }
    for (int i=0;i<n;++i) {
        int nd = (n - a[i]) % n;
        multiset <int>::iterator it = ms.lower_bound(nd);
        if (it == ms.end()) it = ms.begin();
        printf("%d%c", (a[i] + *it) % n, i + 1 < n? ' ':'\n');
        ms.erase(it);
    }
}