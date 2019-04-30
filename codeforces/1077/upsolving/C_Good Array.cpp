#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    pair<int,int> a[200000];
    int n, num;
    long long sum = 0;
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        scanf("%d", &num);
        a[i] = {num, i+1};
        sum += num;
    }

    sort(a, a+n);
    vector<int> ans;
    for (int i=0;i<n-1;++i) {
        if (sum - a[i].first - a[n-1].first == a[n-1].first) ans.push_back(a[i].second);
    }
    if (sum - a[n-1].first - a[n-2].first == a[n-2].first) ans.push_back(a[n-1].second);
    
    printf("%d\n", ans.size());
    for (int i=0;i<ans.size();++i) printf("%d ", ans[i]);
}