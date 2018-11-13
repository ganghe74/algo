#include <iostream>
using namespace std;
int main() {
    int d[1001];
    int count = 1, num = 1;
    for (int i=1;i<=1000;++i) {
        d[i] = num;
        ++count;
        if (count > num) {
            count = 1;
            ++num;
        }
    }
    int A, B, sum = 0;
    scanf("%d %d", &A, &B);
    for (int i=A;i<=B;++i) sum += d[i];
    printf("%d", sum);
}