// https://www.acmicpc.net/problem/11723
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int T, x, S = 0;
    char op[10];
    scanf("%d", &T);
    while (T--) {
        scanf("%s", &op);
        if (strcmp(op, "add") == 0) {
            scanf("%d", &x);
            S = S | (1 << x);
        }
        else if (strcmp(op, "remove") == 0) {
            scanf("%d", &x);
            S = S & ~(1 << x);
        }
        else if (strcmp(op, "check") == 0) {
            scanf("%d", &x);
            if (S & (1 << x)) printf("1\n");
            else printf("0\n");
        }
        else if (strcmp(op, "toggle") == 0) {
            scanf("%d", &x);
            S = S ^ (1 << x);
        }
        else if (strcmp(op, "all") == 0) {
            S = (1 << 21) - 2;
        }
        else if (strcmp(op, "empty") == 0) {
            S = 0;
        }
    }
}