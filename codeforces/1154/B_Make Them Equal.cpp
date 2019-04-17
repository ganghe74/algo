#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> s;
    int n, ai;
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        scanf("%d", &ai);
        s.insert(ai);
        if (s.size() > 3) break;
    }
    if (s.size() == 1) puts("0");
    else if (s.size() == 2) {
        int ans = *(--s.end()) - *s.begin();
        if (ans % 2 == 0) ans /= 2;
        printf("%d", ans);
    }
    else if (s.size() == 3) {
        int mini = *s.begin();
        int maxi = *(--s.end());
        int medi = *(++s.begin());
        if (mini + maxi == medi * 2) printf("%d", maxi - medi);
        else puts("-1");
    }
    else {
        puts("-1");
    }
}