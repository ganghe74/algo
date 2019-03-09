#include <iostream>
#include <string>
using namespace std;
int solve(string num) {
    int ret = 0;
    for (int i=0;i<num.size();++i) ret += num[i]-'0';
    if (ret >= 10) return solve(to_string(ret));
    return ret;
}
int main() {
    while (1) {
        string N;
        cin >> N;
        if (N == "0") return 0;
        cout << solve(N) << '\n';
    }
}