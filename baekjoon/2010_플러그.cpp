#include <iostream>
using namespace std;
int main() {
    int N, temp, answer = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &temp);
        answer += temp - 1;
    }
    printf("%d", answer+1);
}