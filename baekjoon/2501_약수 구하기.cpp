#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a;
    for (int i=1;i<=N;++i) {
        if (N % i == 0) a.push_back(i);
    }
    cout << a[K-1];
}