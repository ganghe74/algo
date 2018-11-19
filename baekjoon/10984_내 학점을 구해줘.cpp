#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int credit = 0;
        double grade = 0;
        for (int i=0;i<N;++i) {
            int x;
            double y;
            scanf("%d %lf", &x, &y);
            credit += x;
            grade += x*y;
        }
        printf("%d %0.1f\n", credit, grade / credit);
    }
}