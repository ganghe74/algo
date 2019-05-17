#include <bits/stdc++.h>
using namespace std;

int main() {
    char vowel[6] = "aeiou";
    int k;
    cin >> k;
    bool find = false;
    int n, m;
    for (int i=5;i<k;++i) {
        if (k % i == 0) {
            if (i >= 5 && k/i >= 5) {
                n = i;
                m = k / i;
                find = true;
                break;
            }
            
        }
    }
    if (!find) {
        puts("-1");
        return 0;
    }

    int start = 0;
    char ans[n][m+1];
    for (int i=0;i<n;++i) {
        int idx = start++;
        for (int j=0;j<m;++j) {
            ans[i][j] = vowel[idx%5];
            idx++;
        }
        ans[i][m] = '\0';
    }

    for (int i=0;i<n;++i) printf("%s", ans[i]);
    
}