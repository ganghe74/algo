#include <bits/stdc++.h>
using namespace std;

vector<int> d(1000001, -1); // 1에 도달가능한가?
bool p[1000001];

bool check(int n) {
    if (n == 1) return 1;
    if (d[n] != -1) return d[n];
    int next = 0, copy = n;
    while (copy > 0) {
        next += (copy%10) * (copy%10);
        copy /= 10;
    }
    d[n] = 0;
    d[n] = check(next);
    return d[n];
}

int main() {
    vector<int> ss;
    for (int i=2;i<=1000000;++i) {
        if (!p[i]) {
            if (check(i)) ss.push_back(i);
            for (int j=2;i*j<=1000000;++j) p[i*j] = 1;
        }
    }
    int n;
    scanf("%d", &n);
    for (int x : ss) {
        if (x > n) break;
        printf("%d\n", x);
    }
}