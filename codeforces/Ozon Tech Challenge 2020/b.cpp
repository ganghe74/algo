#include <bits/stdc++.h>
using namespace std;

int n;
char s[1001];

int main() {
    scanf("%s", s);
    n = strlen(s);
    int l = 0, r = n-1;
    vector<int> ans;
    while (l < r) {
        while (l < n && s[l] != '(') l++;
        while (r >= 0 && s[r] != ')') r--;
        if (l < r && s[l] == '(' && s[r] == ')') {
            ans.push_back(l++);
            ans.push_back(r--);
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.empty()) puts("0");
    else {
        printf("1\n%d\n", int(ans.size()));
        for (int x : ans) printf("%d ", x+1);
    }
}
