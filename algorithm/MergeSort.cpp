#include <iostream>
using namespace std;

int a[10] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};

void merge(int start, int end) {
    int b[end-start];
    int mid = (start+end) / 2;
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
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
    for (int n : a) printf("%d ", n);
    sort(0, 9);
    printf("\n");
    for (int n : a) printf("%d ", n);
}