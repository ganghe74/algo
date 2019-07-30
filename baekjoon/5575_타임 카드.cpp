#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i=0;i<3;++i) {
        int begin, end;
        int h, m, s;
        scanf("%d%d%d", &h, &m, &s);
        begin = h * 3600 + m * 60 + s;
        scanf("%d%d%d", &h, &m, &s);
        end = h * 3600 + m * 60 + s;
        end -= begin;
        printf("%d %d %d\n", end / 3600, end % 3600 / 60, end % 60);
    }
}