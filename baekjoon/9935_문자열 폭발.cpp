#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[1000001], bomb[37];
    scanf("%s %s", s, bomb);

    int n = strlen(bomb);
    vector<char> a;
    for (int i=0;s[i]!='\0';++i) {
        a.push_back(s[i]);
        bool isBomb = true;
        if (a.size() >= n) {
            int idx_a = a.size()-1;
            int idx_b = n-1;
            while (idx_b >= 0) {
                if (a[idx_a--] != bomb[idx_b--]) isBomb = false;
            }
        }
        else isBomb = false;
        if (isBomb) {
            for (int i=0;i<n;++i) a.pop_back();
        }
    }
    if (a.size() == 0) puts("FRULA");
    else {
        for (char x : a) putchar(x);
    }
}