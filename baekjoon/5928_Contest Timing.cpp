#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, H, M;
    scanf("%d%d%d", &D, &H, &M);
    int t = (D-11) * 1440 + (H-11) * 60 + M-11;
    printf("%d", max(t, -1));
}