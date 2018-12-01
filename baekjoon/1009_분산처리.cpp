#include <iostream>
using namespace std;
int main() {
    int cycle[10][4] = {
        {0},
        {1},
        {6,2,4,8},
        {1,3,9,7},
        {6,4},
        {5},
        {6},
        {1,7,9,3},
        {6,8,4,2},
        {1,9}
    };
    int cycle_length[10] = {1,1,4,4,2,1,1,4,4,2};
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, ans;
        scanf("%d%d", &a, &b);
        ans = cycle[a%10][b%cycle_length[a%10]];
        if (ans == 0) ans = 10;
        printf("%d\n", ans);
    }
}