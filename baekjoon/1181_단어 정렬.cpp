#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string& a, string& b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}
int main() {
    int N;
    scanf("%d", &N);
    string s[N];
    for (int i=0;i<N;++i) {
        cin >> s[i];
    }
    sort(s,s+N, cmp);
    N = (int)(unique(s,s+N) - s);
    for (int i=0;i<N;++i) {
        cout << s[i] << endl;
    }
}