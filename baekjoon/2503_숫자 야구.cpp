#include <iostream>
using namespace std;
pair<int, pair<int,int>> a[100];

bool isValidNum(int n) {
    int a = n / 100;
    int b = n / 10 % 10;
    int c = n % 10;
    if (a == 0 || b == 0 || c == 0) return false;
    if (a == b || b == c || a == c) return false;
    return true;
}

pair<int, int> go(int ans, int guess) {
    int s = 0, b= 0;
    int a1 = ans / 100, b1 = ans / 10 % 10, c1 = ans % 10;
    int a2 = guess / 100, b2 = guess / 10 % 10, c2 = guess % 10;
    if (a1 == a2) s++;
    if (b1 == b2) s++;
    if (c1 == c2) s++;
    if (a2 == b1 || a2 == c1) b++;
    if (b2 == a1 || b2 == c1) b++;
    if (c2 == a1 || c2 == b1) b++;
    return {s, b};
}

int main() {
    int N, num, s, b, ans = 0;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d%d%d", &num, &s, &b);
        a[i].first = num;
        a[i].second = {s, b};
    }
    for (int i=100;i<1000;++i) {
        if (!isValidNum(i)) continue;
        for (int j=0;j<N;++j) {
            if (a[j].second != go(i, a[j].first)) {
                ans--;
                break;
            }
        }
        ans++;
    }
    printf("%d", ans);
}