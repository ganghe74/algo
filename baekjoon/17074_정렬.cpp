#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &a, int ignore) {
    for (int i=0;i<a.size()-1;++i) {
        
        if (a[i] > a[i+1]) return false;
    }
    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> a(N);
    for (int i=0;i<N;++i) {
        scanf("%d", &a[i]);
    }
    queue<int> q;
    for (int i=0;i<N-1;++i) {
        if (a[i] > a[i+1]) {
            q.push(i);
            q.push(i+1);
        }
    }

    if (q.size() == 0) printf("%d", a.size());
    else if (q.size() == 2) {
        int i = q.front(), ans = 0;
        if (a[i-1] <= a[i+1]) ans++;
        if (i+2 < a.size()) {
            if (a[i] <= a[i+2]) ans++;
        }
        else ans++;
        printf("%d", ans);
    }
    else printf("0");
}