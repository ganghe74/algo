#include <bits/stdc++.h>
using namespace std;
int d[1500000] = {0, 1};
int main() {
    for (int i=2;i<=1500000;++i) d[i] = (d[i-2] + d[i-1]) % 1000000;
    long long n;
    cin >> n;
    cout << d[n%1500000];
}