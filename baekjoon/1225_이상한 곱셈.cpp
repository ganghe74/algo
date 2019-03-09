#include <iostream>
using namespace std;
int main() {
    string A, B;
    cin >> A >> B;
    long long ans = 0;
    for (char n : A) {
        for (char m : B) ans += (n-'0') * (m-'0');
    }
    cout << ans;
}