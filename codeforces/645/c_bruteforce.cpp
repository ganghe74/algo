#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int a[100][100];
set<int> st;
int cnt = 0;
void bf(int x1, int y1, int x2, int y2, int s) {
    s += a[x1][y1];
    if(x1 == x2 && y1 == y2) {
        cnt++;
        st.insert(s);
    }
    if (x1 < x2)
        bf(x1+1, y1, x2, y2, s);
    if (y1 < y2)
        bf(x1, y1+1, x2, y2, s);
}

int main() {
    int x = 1;
    for (int i=0;i<50;++i) {
        for (int r=0;r<=i;++r) {
            a[r][i-r] = x++;
        }
    }
    for (int i=0;i<5;++i) {
        for (int j=0;j<5;++j) printf("%d ", a[i][j]);
        puts("");
    }



    int t;
    scanf("%d", &t);
    while (t--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        cnt = 0;
        st.clear();
        x1--; y1--; x2--; y2--;
        bf(x1, y1, x2, y2, 0);
        printf("%d (%d)\n", cnt, st.size());
    }
}
