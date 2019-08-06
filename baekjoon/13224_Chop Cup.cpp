#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[51];
    scanf("%s", s);
    int a[3] = {1};
    for (int i=0;s[i]!='\0';++i) {
        if (s[i] == 'A') swap(a[0], a[1]);
        else if (s[i] == 'B') swap(a[1], a[2]);
        else swap(a[0], a[2]);
    }
    if (a[0]) puts("1");
    else if (a[1]) puts("2");
    else puts("3");
}