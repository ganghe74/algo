#include <iostream>
using namespace std;
int main() {
    int N, num = 1, digit = 0, answer = 0;
    scanf("%d", &N);
    while (N >= num-1) {
        num *= 10;
        digit += 1;
        answer += (num - num/10) * digit;
    }
    answer += digit * (N - num + 1);
    printf("%d", answer);
}