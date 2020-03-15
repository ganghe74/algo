#include <bits/stdc++.h>
using namespace std;

int f[10][2] = {
    {1, 3},
    {9, 2},
    {1, 3},
    {4, 9},
    {5, 9},
    {5, 6},
    {1, 7},
    {8, 7},
    {5, 2},
    {9, 9}
};
char s[151];

int main() {
    int n = 0;
    scanf("%s", s);
    for (int i=0;s[i]!='\0';++i)
        n = f[n][s[i]-'0'];
    puts((n == 2 || n == 6 || n == 7) ? "SUBMARINE" : "NOISE");
}
