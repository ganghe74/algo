#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, w;
    cin >> k >> n >> w;
    int need = w*(w+1)/2 * k - n;
    cout << max(0, need);
}