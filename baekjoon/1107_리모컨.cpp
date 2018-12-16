#include <iostream>
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
using namespace std;
bool broken[10];
int possible(int c) {
    if (c == 0) {
        if (broken[0]) return 0;
        else return 1;
    }
    int len = 0;
    while (c > 0) {
        if (broken[c%10]) return 0;
        len++;
        c /= 10;
    }
    return len;
}
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i=0;i<M;++i) {
        int temp;
        scanf("%d", &temp);
        broken[temp] = true;
    }
    int answer = abs(N-100);
    for (int i=0;i<1000000;++i) {
        int len = possible(i);
        if (len != 0) answer = min(answer, len+abs(N-i));
    }
    printf("%d", answer);
}