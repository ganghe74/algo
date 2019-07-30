#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 0, 0};
    char x;
    while ((x = getchar()) != EOF) {
        if (x == 'A') swap(a[0], a[1]);
        if (x == 'B') swap(a[1], a[2]);
        if (x == 'C') swap(a[0], a[2]);
    }
    if (a[0]) printf("1");
    else if (a[1]) printf("2");
    else printf("3");
}