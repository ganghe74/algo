#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint n, a[100000];

lint f(lint d) {
    lint y = 0;
    for (int i=1;i<n;++i)
        y += abs(d*i - a[i]);
    return y;
}

int main() {
    cin >> n;
    for (int i=0;i<n;++i)
        cin >> a[i];
    lint x = 0;
    lint dx = (1LL << 30);
    while (dx) {
        if (x - dx >= 1 && f(x-dx) <= f(x)) x -= dx;
        else if (f(x+dx) <= f(x)) x += dx;
        dx /= 2;
    }
    cout << f(x);
}
