#include <iostream>
using namespace std;
int main() {
    int N, W, H, match;
    scanf("%d%d%d", &N, &W, &H);
    for (int i=0;i<N;++i) {
        scanf("%d", &match);
        if (match * match <= W * W + H * H) printf("DA\n");
        else printf("NE\n");
    }
}