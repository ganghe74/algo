#include <bits/stdc++.h>
using namespace std;

int main() {
    int b[2], d[2], j[2];
    scanf("%d%d%d%d%d%d", &b[0], &b[1], &d[0], &d[1], &j[0], &j[1]);
    int bessie = min(abs(b[0]-j[0]), abs(b[1]-j[1]));
    bessie += max(abs(b[0]-j[0]), abs(b[1]-j[1])) - bessie;
    int daisy = abs(d[0]-j[0]) + abs(d[1]-j[1]);
    if (bessie == daisy) puts("tie");
    else if (bessie < daisy) puts("bessie");
    else puts("daisy");
}