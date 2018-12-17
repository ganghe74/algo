#include <iostream>
#include <string>
#include <queue>
using namespace std;
bool prime[10001];
int change(int num, int index, int digit) {
    if (index == 0 && digit == 0) return -1;
    string s = to_string(num);
    s[index] = digit + '0';
    return stoi(s);
}
int main() {
    for (int i=2;i<=10000;++i) {
        if (!prime[i]) {
            for (int j=2;j*i<=10000;++j) {
                prime[i*j] = true;
            }
        }
    }
    for (int i=2;i<10000;++i) prime[i] = !prime[i];
    int T;
    scanf("%d", &T);
    while (T--) {
        bool check[10000] = {0};
        int d[10000] = {0};
        int A, B;
        scanf("%d%d", &A, &B);
        queue<int> q;
        q.push(A);
        check[A] = true;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i=0;i<4;++i) {
                for (int j=0;j<10;++j) {
                    int next = change(now, i, j);
                    if (next != -1) {
                        if (prime[next] && !check[next]) {
                            q.push(next);
                            check[next] = true;
                            d[next] = d[now] + 1;
                        }
                    }
                }
            }
        }
        if(!check[B]) printf("impossible\n");
        else printf("%d\n", d[B]);
    }
}