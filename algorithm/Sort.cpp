#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void insertion_sort(int a[], int n) {
    int i, j, key;
    for (i=1;i<n;++i) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
}

void bubble_sort(int a[], int n) {
    for (int i=0;i<n-1;++i) {
        for (int j=0;j<n-i-1;++j) {
            if (a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }
}

void merge(int a[], int l, int r) {
    int mid = (l + r) / 2;
    int i = l, j = mid + 1, k = 0;
    int b[r-l+1];
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i=l;i<=r;++i) a[i] = b[i-l];
}

void merge_sort(int a[], int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge(a, l, r);
}

void heap_sort(int a[], int n) {
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i=0;i<n;++i) heap.push(a[i]);
    for (int i=0;i<n;++i) {
        a[i] = heap.top();
        heap.pop();
    }
}

int main() {
    int n;
    cout << "Array Size > ";
    cin >> n;
    cout << n << " Elements >\n";
    int a[n];
    for (int i=0;i<n;++i) cin >> a[i];

    merge_sort(a, 0, n);

    cout << "Sorted Array\n";
    for (int i=0;i<n;++i) cout << a[i] << " ";
}