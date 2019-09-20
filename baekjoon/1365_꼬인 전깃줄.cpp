#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x;
    vector<int> lis = {0};
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &x);
        if (lis.back() < x) lis.push_back(x);
        else {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            *it = x;
        }
    }
    printf("%d", N - lis.size() + 1);
}