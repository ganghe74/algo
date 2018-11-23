#include <iostream>
using namespace std;
int main() {
    int in, S1 = 0, S2 = 0;
    for (int i=0;i<4;++i) {
        scanf("%d", &in);
        S1 += in;
    }
    for (int i=0;i<4;++i) {
        scanf("%d", &in);
        S2 += in;
    }
    printf("%d", S1>S2?S1:S2);
}