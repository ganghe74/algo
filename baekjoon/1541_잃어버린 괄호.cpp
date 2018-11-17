#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, num = "";
    vector<int> nums;
    bool minus = false;
    cin >> s;
    s += "+";
    for (int i=0;i<s.size();++i) {
        if (s[i] == '+' || s[i] == '-') {
            if (minus) nums.push_back(-stoi(num));
            else nums.push_back(stoi(num));
            num = "";
            if (s[i] == '-') minus = true;
        }
        else {
            num += s[i];
        }
    }
    int answer = 0;
    for (int x : nums) {
        answer += x;
    }
    cout << answer;
}