#include <iostream>
#include <vector>
using namespace std;
int bino[2001][2001];
int main() {
    long long N, K, M, ans = 1;
    cin >> N >> K >> M;
    
    for (int i=0;i<=2000;++i) {
        bino[i][0] = bino[i][i] = 1;
        for (int j=1;j<i;++j) {
            bino[i][j] = (bino[i-1][j-1] + bino[i-1][j]) % M;
        }
    }

    vector<int> a, b;
    while (N > 0 && K > 0) {
        a.push_back(N % M);
        b.push_back(K % M);
        N /= M;
        K /= M;
    }
    for (int i=0;i<a.size();++i) {
        ans *= bino[a[i]][b[i]];
        ans %= M;
    }
    cout << ans;
}