#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    string pattern, s;
    cin >> N >> pattern;
    int front = 0, back = 0;
    for (int i=0;pattern[i]!='*';++i) front++;
    for (int i=pattern.size()-1;pattern[i]!='*';--i) back++;
    while (N--) {
        cin >> s;
        bool ok = true;
        if (s.size() < front + back) ok = false;
        else {
            for (int i=0;i<front;++i) {
                if (s[i] != pattern[i]) ok = false;
            }
            for (int i=0;i<back;++i) {
                if (s[s.size()-i-1] != pattern[pattern.size()-i-1]) ok = false;
            }
        }
        if (ok) puts("DA");
        else puts("NE");
    }
}