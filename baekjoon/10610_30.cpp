#include <bits/stdc++.h>
using namespace std;
int main() {
    string N;
    cin >> N;
    sort(N.begin(), N.end());
    reverse(N.begin(), N.end());
    int sum = 0;
    for (int i=0;i<N.size();++i) {
        sum += N[i] - '0';
    }
    if (sum % 3 == 0 && N[N.size()-1] == '0') cout << N;
    else cout << -1;
}