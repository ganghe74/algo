#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, ab=0;
    scanf("%d", &N);
    while (ab*(ab+1)/2 < N) ab++;
    N -= ab*(ab-1)/2;
    printf("%d %d", ab+1-N, N);
}