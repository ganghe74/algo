#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int main() {
    int N;
    scanf("%d", &N);
    vector<lint> a, b;
    while (N--) {
        int x;
        scanf("%d", &x);
        if (x >= 0) a.push_back(x);
        else b.push_back(x);
    }
    a.push_back(1e13); b.push_back(-1e12);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());
    lint i=0, j=0, m=1e10, ma=0, mb=0;
    if (a.size() == 1) printf("%lld %lld", b[1], b[0]);
    else if (b.size() == 1) printf("%lld %lld", a[0], a[1]);
    else {
        lint i=0, j=0, m=a[0]+a[1], ma=a[1], mb=a[0];
        if (-b[0]-b[1] < m) {
            m = -b[0]-b[1];
            ma=b[0];
            mb=b[1];
        }
        while (i < a.size() && j < b.size()) {
            if (abs(a[i] + b[j]) < m) {
                m = abs(a[i]+b[j]);
                ma = a[i];
                mb = b[j];
            }
            if (i >= a.size()-1) j++;
            else if (j >= b.size()-1) i++;
            else if (abs(a[i]+b[j+1]) < abs(a[i+1]+b[j])) j++;
            else i++;
        }
        printf("%lld %lld", mb, ma);
    }
}