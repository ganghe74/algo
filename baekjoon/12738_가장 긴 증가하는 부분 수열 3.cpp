#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a = {int(-2e+9)};
    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        if (x > a.back()) a.push_back(x);
        else {
            auto it = lower_bound(a.begin(), a.end(), x);
            *it = x;
        }
    }
    printf("%d", a.size()-1);
}