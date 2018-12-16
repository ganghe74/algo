#include <iostream>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int sum = 0, week = 0;
        char history[31] = {};
        scanf("%s", history);
        for (char x : history) {
            if (x >= '0') {
                int p;
                if (x >= 'A') p = x - 'A' + 10;
                else p = x - '0';
                if (sum + p >= 30 && sum < 30) {
                    if (sum + p < 40) week += 3;
                }
                else if (sum + p >= 20 && sum < 20) week += 2;
                else if (sum + p >= 10 && sum < 10) week += 1;
                sum += p;
            }
        }
        printf("%d", week);
        if (sum >= 50) printf("(09)");
        else if (sum >= 40) printf("(weapon)");
        printf("\n");
    }
}