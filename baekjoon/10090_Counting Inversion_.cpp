#include <bits/stdc++.h>
using namespace std;

int n, a[1000000];
long long ans;

void merge(int l, int r) {
    int mid = (l + r) / 2;
    int i = l, j = mid + 1, k = 0;
    int b[r-l+1];
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) b[k++] = a[i++];
        else {
            ans += mid - i + 1;
            b[k++] = a[j++];
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (int i=l;i<=r;++i) a[i] = b[i-l];
}

void merge_sort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    merge(l, r);
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);    
    merge_sort(0, n-1);
    printf("%lld", ans);
}