#include <iostream>
#include <map>
using namespace std;
int main() {
    map<int, int> m;
    int n, sum = 0;
    for (int i=0;i<5;++i) {
        scanf("%d", &n);
        m[n]++;
        sum += n;
    }
    int ans = 1000;
    for (auto pi : m) {
        if (pi.second >= 2) ans = min(ans, sum - pi.first*min(3,pi.second));
    }
    printf("%d", min(ans, sum));
}