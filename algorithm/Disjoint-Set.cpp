#include <iostream>
using namespace std;

int parent[10001];

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    parent[x] = y;
}

int main() {
    for (int i=0;i<=10000;++i) parent[i] = i;
    int op, a, b;
    puts("0 : Exit");
    puts("1 a b : Union(a, b)");
    puts("2 a : Find(a)");
    puts("===================");
    while (true) {
        scanf("%d", &op);
        if (op == 0) break;
        else if (op == 1) {
            scanf("%d %d", &a, &b);
            printf("Union(%d, %d)\n", a, b);
            Union(a, b);
        }
        else if (op == 2) {
            scanf("%d", &a);
            printf("Find(%d) = %d\n", a, Find(a));
        }
    }
    puts("Done.");
}