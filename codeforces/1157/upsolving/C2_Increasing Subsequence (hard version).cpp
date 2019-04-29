#include <iostream>
#define LEFT 0
#define RIGHT 1
using namespace std;

int a[200005];
int n, now = 0;

int judge(int l, int r) {
    if (a[l] <= now) return RIGHT;
    if (a[r] <= now) return LEFT;
    if (a[l] == a[r]) {
        int cnt_l = 0, cnt_r = 0;
        while (a[l] < a[l+1] && l < n-1) {
            l++;
            cnt_l++;
        }
        while (a[r] < a[r-1] && r > 0) {
            r--;
            cnt_r++;
        }
        if (cnt_l > cnt_r) return LEFT;
        else return RIGHT;
    }

    if (a[l] < a[r]) return LEFT;
    if (a[l] > a[r]) return RIGHT;
    return LEFT;
}

int main() {
    char ans[200005];
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    int l=0, r=n-1, i=0;

    while (now < a[l] || now < a[r]) {
        if (judge(l, r) == LEFT) {
            now = a[l++];
            ans[i++] = 'L';
        }
        else {
            now = a[r--];
            ans[i++] = 'R';
        }
    }
    ans[i] = '\0';
    printf("%d\n%s", i, ans);
}