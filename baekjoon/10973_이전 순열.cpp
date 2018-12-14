#include <iostream>
using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    a = b;
    *b = temp;
}
bool prev_permutation(int *a, int n) {
    int i = n-1;
    while (i > 0 && a[i-1] <= a[i]) i -= 1;
    if (i <= 0) return false;
    int j = n-1;
    while (a[j] >= a[i-1]) j -= 1;
    swap(a[i-1], a[j]);
    j = n-1;
    while (i < j) {
        swap(a[i], a[j]);
        i += 1; j -= 1;
    }
    return true;
}
int main() {
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    if (prev_permutation(a, N))
        for (int i=0;i<N;++i) printf("%d ", a[i]);
    else printf("-1");
}