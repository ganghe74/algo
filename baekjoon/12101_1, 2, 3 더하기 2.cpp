#include <iostream>
#include <vector>
using namespace std;

int n, k, cnt = 0;
vector<int> ans;

bool f(int now) {
    if (now > n) return false;
    if (now == n) {
        cnt++;
        if (cnt == k) {
            for (int i=0;i<ans.size()-1;++i) {
                printf("%d+", ans[i]);
            }
            printf("%d", ans[ans.size()-1]);
            return true;
        }
        return false;
    }
    for (int i=1;i<=3;++i) {
        ans.push_back(i);
        if (f(now+i)) return true; 
        ans.pop_back();
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &k);
    if (!f(0)) printf("-1");
}