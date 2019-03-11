#include <iostream>
using namespace std;
int main() {
    int ans = 0, now = 0;
    for (int i=0;i<4;++i) {
        int out, in;
        scanf("%d%d", &out, &in);
        now -= out;
        now += in;
        ans = max(ans, now);
    }
    printf("%d", ans);
}