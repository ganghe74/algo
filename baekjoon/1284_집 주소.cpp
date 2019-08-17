#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (true) {
        scanf("%d", &N);
        if (N == 0) break;
        int width = 1;
        while (N > 0) {
            if (N % 10 == 0) width += 5;
            else if (N % 10 == 1) width += 3;
            else width += 4;
            N /= 10;
        }
        printf("%d\n", width);
    }
}