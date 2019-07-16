#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, M, S;
    scanf("%d:%d:%d", &H, &M, &S);
    int T1 = H * 3600 + M * 60 + S;
    scanf("%d:%d:%d", &H, &M, &S);
    int T2 = H * 3600 + M * 60 + S;
    T2 -= T1;
    if (T2 < 0) T2 += 86400;
    printf("%02d:%02d:%02d", T2 / 3600, T2 % 3600 / 60, T2 % 60);
}