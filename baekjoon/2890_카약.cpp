#include <bits/stdc++.h>
using namespace std;
pair<int,int> pos[10];
int ranking[9];
char s[51][51];
int main() {
    int R, C;
    scanf("%d%d", &R, &C);
    for (int i=0;i<R;++i) scanf("%s", s[i]);
    for (int i=0;i<R;++i) {
        for (int j=1;j<C-1;++j) {
            if (isdigit(s[i][j])) pos[s[i][j]-'1'] = {j, s[i][j]-'1'};
        }
    }
    sort(pos, pos+9);
    int cnt = 1;
    for (int i=8;i>=0;--i) {
        if (pos[i].first < pos[i+1].first) cnt++;
        ranking[pos[i].second] = cnt;
    }
    for (int i=0;i<9;++i) printf("%d\n", ranking[i]);
}