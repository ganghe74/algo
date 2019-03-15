#include <iostream>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    printf("%d", __builtin_popcount(N) == 1);
}