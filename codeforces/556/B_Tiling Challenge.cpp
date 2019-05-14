#include <iostream>
using namespace std;

int n;
int a[52][52];
 
bool solve() {
    bool c = 0;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (a[i][j] == 0) {
                c = true;
                if (!a[i][j+1] && !a[i][j-1] && !a[i-1][j] && !a[i+1][j]) {
                    a[i][j] = 1;
                    a[i][j+1] = 1;
                    a[i][j-1] = 1;
                    a[i+1][j] = 1;
                    a[i-1][j] = 1;
                    if (solve()) return true;
                    else return false;
                }
            }
        }
    }
    if (!c) return true;
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n+2;++i) {
        a[0][i] = 1;
        a[n+1][i] = 1;
        a[i][0] = 1;
        a[i][n+1] = 1;
    } 

    char tmp;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            scanf(" %c", &tmp);
            if (tmp == '#') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    if (solve()) printf("YES");
    else printf("NO");
}