#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        vector<int> a(n);
        vector<bool> peak(n);
        for (int i=0;i<n;++i)
            scanf("%d", &a[i]);

        for (int i=0;i<n;++i) {
            bool p = true;
            if (i-1 >= 0 && a[i-1] >= a[i]) p = false;
            if (i+1 <  n && a[i+1] >= a[i]) p = false;
            peak[i] = p;
        }

        vector<int> numofpeaks(n-k+1);
        int cnt = 0;
        for (int i=1;i<k-1;++i)
            if (peak[i]) cnt++;

        for (int i=0;i<=n-k;++i) {
            numofpeaks[i] = cnt;
            if (peak[i+1]) cnt--;
            if (peak[i+k-1]) cnt++;
        }

        int maxl = 0;
        for (int i=0;i<=n-k;++i)
            if (numofpeaks[i] > numofpeaks[maxl]) maxl = i;

        printf("%d %d\n", numofpeaks[maxl]+1, maxl+1);

    }
}
