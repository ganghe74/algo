#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    if (n < k * 1ll * (k + 1) / 2) {
        cout << "NO" << endl;
        return 0;
    }

    int nn = n - k * (k+1) / 2;
    vector<int> a(k);

    for (int i=0;i<k;++i) a[i] = i + 1 + (nn / k) + (i >= k - nn % k);

    if (nn != k - 1) {
        cout << "YES" << endl;
        for (int i=0;i<k;++i) cout << a[i] << " ";
        cout << endl;
    }
    else {
        if (k > 3) {
            --a[1];
            ++a[k-1];
        }
        if (k == 2 || k == 3) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            for (int i=0;i<k;++i) cout << a[i] << " ";
            cout << endl;
        }
    }
}