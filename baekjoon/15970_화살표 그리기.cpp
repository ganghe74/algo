#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[100001];
int main() {
    int N, coord, color, ans = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d%d", &coord, &color);
        a[color].push_back(coord);
    }
    for (int i=1;i<=100000;++i) {
        if (!a[i].empty()) {
            sort(a[i].begin(), a[i].end());
            ans += a[i][1] - a[i][0];
            ans += a[i][a[i].size()-1] - a[i][a[i].size()-2];
            if (a[i].size() == 2) continue;
            for (int j=1;j<a[i].size()-1;++j) {
                ans += min(a[i][j]-a[i][j-1], a[i][j+1]-a[i][j]);
            }
        }
    }
    printf("%d", ans);
}