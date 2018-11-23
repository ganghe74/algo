#include <iostream>
using namespace std;

int N, M, answer;
int road[1000002];

int minFlip() {
    int ret = 0;
    for (int i=1;i<=N;++i) {
        if (road[i] && !road[i-1]) ret += 1;
    }
    return ret;
}

void flip(int x) {
    if (!road[x]) {
        road[x] = 1;
        if (road[x-1] && road[x+1]) {
            answer -= 1;
        }
        else if (!road[x-1] && !road[x+1]) {
            answer += 1;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i=1;i<=N;++i) scanf("%d", &road[i]);
    answer = minFlip();
    while (M--) {
        int exe;
        scanf("%d", &exe);
        if (exe) {
            scanf("%d", &exe);
            flip(exe);
        }
        else {
            printf("%d\n", answer);
        }
    }
}