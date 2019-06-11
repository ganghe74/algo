#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    while (true) {
        scanf("%d", &N);
        if (N == 0) break;
        vector<int> a(N);
        for (int i=0;i<N;++i) scanf("%d", &a[i]);
        a.erase(unique(a.begin(), a.end()), a.end());
        for (int i=0;i<a.size();++i) printf("%d ", a[i]);
        puts("$");
    }
}