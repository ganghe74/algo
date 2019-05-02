#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, num;
    scanf("%d", &N);
    vector<int> a(N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    a.push_back(0);
    sort(a.begin(), a.end());
    for (int i=0;i<N;++i) {
        if (a[i] + 1 != a[i+1]) {
            printf("%d", a[i]+1);
            return 0;
        }
    }
    printf("%d", a[N] + 1);
}