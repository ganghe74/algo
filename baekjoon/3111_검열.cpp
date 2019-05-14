#include <bits/stdc++.h>
using namespace std;

vector<char> al, ar;

int main() {
    char a[26], t[300001];
    scanf("%s", a);
    scanf("%s", t);
    int n = strlen(a);
    int l = 0, r = strlen(t)-1;
    bool left = true;

    while (l <= r) {
        bool isSafe = false;
        if (left) {
            al.push_back(t[l++]);
            if (al.size() >= n) {
                int idx_al = al.size() - 1;
                int idx_a = n - 1;
                while (idx_a >= 0) {
                    if (a[idx_a--] != al[idx_al--]) isSafe = true;
                }
            }
            else isSafe = true;
            if (!isSafe) {
                for (int i=0;i<n;++i) al.pop_back();
                left = false;
            }
        }
        else {
            ar.push_back(t[r--]);
            if (ar.size() >= n) {
                int idx_ar = ar.size() - 1;
                int idx_a = 0;
                while (idx_a < n) {
                    if (a[idx_a++] != ar[idx_ar--]) isSafe = true;
                }
            }
            else isSafe = true;
            if (!isSafe) {
                for (int i=0;i<n;++i) ar.pop_back();
                left = true;
            }
        }
    }
    while (ar.size() > 0) {
        al.push_back(ar[ar.size()-1]);
        ar.pop_back();
        bool isSafe = false;
        if (al.size() >= n) {
            int idx_al = al.size() - 1;
            int idx_a = n - 1;
            while (idx_a >= 0) {
                if (a[idx_a--] != al[idx_al--]) isSafe = true;
            }
        }
        else isSafe = true;
        if (!isSafe) for (int i=0;i<n;++i) al.pop_back();
    }
    for (int i=0;i<al.size();++i) printf("%c", al[i]);
}

// abc
// fabaabcbcabccd