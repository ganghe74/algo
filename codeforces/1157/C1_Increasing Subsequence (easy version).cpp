#include <iostream>
using namespace std;
int main() {
    int a[200005];
    int n;
    char ans[200005];
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);

    int l=0, r=n-1, now=0, i=0;

    while (now < a[l] || now < a[r]) {
        if (a[l] < now) {
            now = a[r--];
            ans[i++] = 'R';
        }
        else if (a[r] < now) {
            now = a[l++];
            ans[i++] = 'L';
        }
        else {
            if (a[l] < a[r]) {
                now = a[l++];
                ans[i++] = 'L';
            }
            else {
                now = a[r--];
                ans[i++] = 'R';
            }
        }
    }
    ans[i] = '\0';
    printf("%d\n%s", i, ans);
}