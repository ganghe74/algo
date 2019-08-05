#include <bits/stdc++.h>
using namespace std;

bool c[9];
int N, ans, a[50][9], p[9];

int calculate() {
    int score = 0, now = 0;
    for (int i=0;i<N;++i) {
        int out = 0;
        bool base[4] = {0};
        while (out < 3) {
            int swing = a[i][p[now]];
            if (!swing) out++;
            else {
                base[0] = 1;
                for (int j=3;j>=0;--j) {
                    if (base[j]) {
                        base[j] = 0;
                        if (j + swing >= 4) score++;
                        else base[j+swing] = 1;
                    }
                }
            }
            now = (now + 1) % 9;
        }
    }
    return score;
}

void choice(int idx) {
    if (idx == 9) {
        int score = calculate();
        ans = max(ans, score);
        return;
    }
    if (idx == 3) {
        choice(idx+1);
        return;
    }
    for (int i=1;i<9;++i) {
        if (!c[i]) {
            c[i] = 1;
            p[idx] = i;
            choice(idx+1);
            c[i] = 0;
        }
    }
}

int main() {
    p[3] = 0; c[0] = 1;
    scanf("%d", &N);
    for (int i=0;i<N;++i)
        for (int j=0;j<9;++j) scanf("%d", &a[i][j]);

    choice(0);
    printf("%d", ans);
}