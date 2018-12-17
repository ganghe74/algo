#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
bool check[10000];
int from[10000];
char how[10000];
int op(int num, char x) {
    if (x == 'D') return num * 2 % 10000;
    else if (x == 'S') {
        if (num == 0) return 9999;
        return num - 1;
    }
    else if (x == 'L') return num%1000*10 + num/1000;
    else if (x == 'R') return num%10*1000 + num/10;
    return -1;
}
void print(int A, int B) {
    if (A == B) return;
    print(A, from[B]);
    printf("%c", how[B]);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(check, 0, sizeof(check));
        memset(from, 0, sizeof(from));
        memset(how, 0, sizeof(how));
        int A, B;
        scanf("%d%d", &A, &B);
        queue<int> q;
        q.push(A);
        check[A] = true;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (char x : "DSLR") {
                int next = op(now, x);
                if (next != -1) {
                    if (!check[next]) {
                        q.push(next);
                        check[next] = true;
                        from[next] = now;
                        how[next] = x;
                    }
                }
            }
        }
        print(A, B);
        printf("\n");
    }
}