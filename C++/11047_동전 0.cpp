#include <iostream>
using namespace std;
int main() {
    int N, K, answer = 0;
    cin >> N >> K;
    int a[N];
    for (int i=0;i<N;++i) {
        cin >> a[i];
    }
    for (int i=N-1; i>=0; --i) {
        answer += K/a[i];
        K %= a[i];
    }
    cout << answer;
}