#include <iostream>
using namespace std;
int a[10001];
void solve(int start, int end) {
    if (start == end) return;
    int idx = start+1;
    while(idx < end && a[idx] < a[start]) idx++;
    solve(start+1, idx);
    solve(idx, end);
    printf("%d\n", a[start]);
}
int main() {
    int num, size = 0;
    while (scanf("%d", &num) != EOF) {
        a[size++] = num;
    }
    solve(0, size);
}