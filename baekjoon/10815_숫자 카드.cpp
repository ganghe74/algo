#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    scanf("%d", &N);
    int card[N];
    for (int i=0;i<N;++i) scanf("%d", &card[i]);
    sort(card, card+N);
    scanf("%d", &M);
    int find[M];
    for (int i=0;i<M;++i) scanf("%d", &find[i]);
    for (int i=0;i<M;++i) {
        int l = 0, r = N-1;
        while (l < r) {
            int mid = (l+r)/2;
            if (card[mid] > find[i]) {
                r = mid - 1;
            }
            else if (card[mid] < find[i]) {
                l = mid + 1;
            }
            else l = r = mid;
        }
        printf("%d ", card[l] == find[i]);
    }
}