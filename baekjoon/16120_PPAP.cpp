#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[1000001];
    scanf("%s", s);
    vector<char> a;
    for (int i=0;s[i]!='\0';++i) {
        a.push_back(s[i]);
        bool isPPAP = true;
        if (a.size() >= 4) {
            int n = a.size();
            if (a[n-4] != 'P' || a[n-3] != 'P' || a[n-2] != 'A' || a[n-1] != 'P') isPPAP = false;
        }
        else isPPAP = false;
        if (isPPAP) {
            for (int j=0;j<4;++j) a.pop_back();
            a.push_back('P');
        }
    }
    if (a.size() == 1 && a[0] == 'P') puts("PPAP");
    else puts("NP");
}