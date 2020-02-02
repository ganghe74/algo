#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x;
    char op[6];
    queue<int> q;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", op);
        if (op[0] == 'p' && op[1] == 'u') {
            scanf("%d", &x);
            q.push(x);
        }
        else if (op[0] == 'p' && op[1] == 'o') {
            if (q.empty()) puts("-1");
            else {
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if (op[0] == 's') printf("%d\n", q.size());
        else if (op[0] == 'e') printf("%d\n", q.empty());
        else if (op[0] == 'f') {
            if (q.empty()) puts("-1");
            else printf("%d\n", q.front());
        }
        else {
            if (q.empty()) puts("-1");
            else printf("%d\n", q.back());
        }
    }
}