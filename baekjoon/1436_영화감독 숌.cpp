#include <iostream>
using namespace std;
int a[10];
void up() {
    for (int i=0;i<9;++i) {
        while (a[i] >= 10) {
            a[i] -= 10;
            a[i+1] += 1;
        }
    }
}
bool find() {
    for (int i=0;i<8;++i) {
        if (a[i] == 6 && a[i+1] == 6 && a[i+2] == 6) return true;
    }
    return false;
}
int main() {
    int N, cnt = 0, num = 0;
    scanf("%d", &N);
    while (cnt < N) {
        num++;
        a[0]++;
        up();
        if (find()) cnt++;
    }
    printf("%d", num);
}