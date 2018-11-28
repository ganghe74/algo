#include <iostream>
using namespace std;

int a[500000];
long long answer = 0;

void merge(int start, int end) {
    int b[end-start];
    int mid = (start+end) / 2;
    int i = start, j = mid + 1, k = 0;
    while (i <= mid || j <= end) {
        if (i <= mid && (a[i] <= a[j] || j > end)) b[k++] = a[i++];
        else {
            answer += (long long)(mid-i+1);
            b[k++] = a[j++];
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= end) b[k++] = a[j++];
    for (int i=start;i<=end;++i)
        a[i] = b[i-start];
}

void sort(int start, int end) {
    if (start == end) return;
    int mid = (start+end) / 2;
    sort(start, mid);
    sort(mid+1, end);
    merge(start, end);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(0, N-1);
    printf("%lld", answer);
}