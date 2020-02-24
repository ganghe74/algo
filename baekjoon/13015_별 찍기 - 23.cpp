#include <bits/stdc++.h>
using namespace std;

int N;

void printline(int space) {
    for (int i=0;i<space;++i) putchar(' ');
    putchar('*');
    for (int i=0;i<N-2;++i) putchar((space) ? ' ' : '*');
    putchar('*');
    for (int i=0;i<2*(N-2-space)+1;++i) putchar(' ');
    if (space < N-1) putchar('*');
    for (int i=0;i<N-2;++i) putchar((space) ? ' ' : '*');
    putchar('*');
    puts("");
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) printline(i);
    for (int i=N-2;i>=0;--i) printline(i);
}
