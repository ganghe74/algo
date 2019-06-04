#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    int now = h * 3600 + m * 60 + s;
    scanf("%d:%d:%d", &h, &m, &s);
    int t = h * 3600 + m * 60 + s;
    if (now >= t) t += 86400;
    t -= now;
    printf("%02d:%02d:%02d", t/3600, t%3600/60, t%60);
}