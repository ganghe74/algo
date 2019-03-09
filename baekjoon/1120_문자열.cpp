#include <iostream>
using namespace std;
int main() {
    int ans = 50;
    string A, B;
    cin >> A >> B;
    for (int i=0;i<=B.size()-A.size();++i) {
        int cnt = 0;
        for (int j=0;j<A.size();++j) {
            if (A[j] != B[j+i]) cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans;
}