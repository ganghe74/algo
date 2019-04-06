#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int a[100];
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a, a+N);
    int ans = a[1]-a[0];
    for (int i=2;i<N;++i) ans = gcd(ans, a[i]-a[i-1]);
    vector<int> factor;
    for (int i=1;i*i<=ans;++i) {
        if (ans % i == 0) {
            if (i == ans / i) factor.push_back(i);
            else {
                factor.push_back(i);
                factor.push_back(ans/i);
            }
        }
    }
    sort(factor.begin(), factor.end());
    for (int i=1;i<factor.size();++i) printf("%d ", factor[i]);
}