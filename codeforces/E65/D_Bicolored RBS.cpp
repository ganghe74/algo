#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char s[200001], ans[200001];
    scanf("%d ", &n);
    scanf("%s", s);
    int depth_0 = 0, depth_1 = 0;
    int idx = 0;
    bool color = 0;

    while (idx < n) {
        if (s[idx] == '(') {
            if (color == 1) {
                ans[idx] = '1';
                depth_1++;
            }
            else {
                ans[idx] = '0';
                depth_0++;
            }
            if (depth_0 > depth_1) color = 1;
            else color = 0;
        }
        else {
            if (depth_0 > 0) {
                ans[idx] = '0';
                depth_0--;
            }
            else {
                ans[idx] = '1';
                depth_1--;
            }
        }
        idx++;
    }
    ans[idx] = '\0';
    printf("%s", ans);
}