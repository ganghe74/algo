#include <iostream>
using namespace std;
int score[9];
bool check[8];
int main() {
    int sum = 0;
    score[8] = -1;
    for (int i=0;i<8;++i) scanf("%d", &score[i]);
    for (int i=0;i<5;++i) {
        int maxIdx = 8;
        for (int j=0;j<8;++j) {
            if (score[maxIdx] < score[j] && !check[j]) {
                maxIdx = j;
            }
        }
        check[maxIdx] = true;
        sum += score[maxIdx];
    }
    printf("%d\n", sum);
    for (int i=0;i<8;++i) {
        if (check[i]) printf("%d ", i+1);
    }
}