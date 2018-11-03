// 완전탐색, 시간초과됨
#include <iostream>
#include <vector>
#define min(a,b) ((a<b)?a:b)
using namespace std;
const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS+1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks) {
    int ok = true;
    for (int i=0;i<CLOCKS;++i) {
        if (clocks[i] != 12) ok = false;
    }
    return ok;
}

void push(vector<int>& clocks, int swtch) {
    for (int i=0;i<CLOCKS;++i) {
        if (linked[swtch][i] == 'x') {
            clocks[i] += 3;
            if(clocks[i] == 15) clocks[i] = 3;
        }
    }
}

int solve(vector<int>& clocks, int swtch) {
    if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
    int ret = INF;
    for (int cnt = 0;cnt<4;++cnt) {
        ret = min(ret, cnt + solve(clocks, swtch + 1));
        push(clocks, swtch);
    }
    return ret;
}

int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        vector<int> clocks(16);
        for (int i=0;i<CLOCKS;++i) {
            scanf("%d", &clocks[i]);
        }
        printf("%d\n", solve(clocks, 0));
        
        clocks.clear();
    }
}