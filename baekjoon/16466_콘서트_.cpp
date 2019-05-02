#include <iostream>
using namespace std;

bool c[1000005];

int main() {
    int N, num;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &num);
        c[num] = 1;
    }
    for (int i=1;i<1000005;++i) {
        if (!c[i]) {
            printf("%d", i);
            break;
        }
    }
}