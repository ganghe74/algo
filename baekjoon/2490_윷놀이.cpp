#include <iostream>
using namespace std;
int main() {
    char yoot[5] = {'D', 'C', 'B', 'A', 'E'};
    int temp, sum;
    for (int t=0;t<3;++t) {
        sum = 0;
        for (int i=0;i<4;++i) {
            scanf("%d", &temp);
            sum += temp;
        }
        printf("%c\n", yoot[sum]);
    }
}