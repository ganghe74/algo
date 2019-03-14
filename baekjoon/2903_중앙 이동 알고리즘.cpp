#include <iostream>
using namespace std;
int main() {
    int N, len = 2;
    scanf("%d", &N);
    while (N--) len = len * 2 - 1;
    printf("%d", len*len);
}