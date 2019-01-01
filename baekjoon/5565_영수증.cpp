#include <iostream>
using namespace std;
int main() {
    int sum, minus;
    scanf("%d", &sum);
    for (int i=0;i<9;++i) {
        scanf("%d", &minus);
        sum -= minus;
    }
    printf("%d", sum);
}