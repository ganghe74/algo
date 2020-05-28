#include <bits/stdc++.h>
using namespace std;

int order(const vector<int> &russian, const vector<int> &korean) {
    int n = russian.size(), wins = 0;
    multiset<int> ratings(korean.begin(), korean.end());
    for (int rus=0; rus<n; ++rus) {
        if (*ratings.rbegin() < russian[rus])
            ratings.erase(ratings.begin());
        else {
            ratings.erase(ratings.lower_bound(russian[rus]));
            ++wins;
        }
    }
    return wins;
}

int tc, n;

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        vector<int> russian(n), korean(n);
        for (int i=0;i<n;++i)
            scanf("%d", &russian[i]);
        for (int i=0;i<n;++i)
            scanf("%d", &korean[i]);
        printf("%d\n", order(russian, korean));
    }
}
