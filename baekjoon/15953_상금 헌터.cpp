#include <iostream>
using namespace std;
int main() {
    int reward2017[15] = {0, 500, 300, 200, 50, 30, 10};
    int reward2018[8] = {0, 512, 256, 128, 64, 32};
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, i, cnt, sum = 0;
        scanf("%d%d", &a, &b);
        for (i=0,cnt=0;cnt<a;++i,cnt+=i);
        sum += reward2017[i] * 10000;
        for (i=0,cnt=0;cnt<b;++i,cnt=(1<<i)-1);
        sum += reward2018[i] * 10000;
        printf("%d\n", sum);
    }
}