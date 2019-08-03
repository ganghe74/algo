#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, w, l, tc=1;
    while (scanf("%d%d%d", &r, &w, &l) == 3) {
        printf("Pizza %d ", tc++);
        if (w*w + l*l > 4*r*r) printf("does not fit ");
        else printf("fits ");
        puts("on the table.");
    }
}