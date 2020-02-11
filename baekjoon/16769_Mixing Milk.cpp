#include <bits/stdc++.h>
using namespace std;
int main() {
    int c[3], m[3];
    for (int i=0;i<3;++i) scanf("%d%d", &c[i], &m[i]);
    for (int i=0;i<100;++i) {
        if (m[i%3] + m[(i+1)%3] > c[(i+1)%3]) {
            m[i%3] -= c[(i+1)%3] - m[(i+1)%3];
            m[(i+1)%3] = c[(i+1)%3];
        }
        else {
            m[(i+1)%3] += m[i%3];
            m[i%3] = 0;
        }
    }
    printf("%d\n%d\n%d", m[0], m[1], m[2]);
}
