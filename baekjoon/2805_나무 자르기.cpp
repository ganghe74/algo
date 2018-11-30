#include <iostream>
#include <vector>
using namespace std;
int N, M;
bool check(vector<int>& a, int x) {
    long long cnt = 0;
    for (int n : a) {
        if (n-x > 0) {
            cnt += n - x;
        }
    }
    return cnt >= M;
}
int main() {
    scanf("%d%d", &N, &M);
    vector<int> a(N);
    int max = -1;
    for (int i=0;i<N;++i) {
        scanf("%d", &a[i]);
        if (max < a[i]) max = a[i];
    }
    int l = 1, r = max;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(a, mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d", r);
}