#include <iostream>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int main() {
    long long A, B, answer;
    scanf("%lld %lld", &A, &B);
    if (A>B) swap(A,B);
    if (A>=0 && B>=0) answer = B*(B+1)/2 - A*(A+1)/2 + A;
    else if (A<0 && B<0) answer = A*(A-1)/2*-1 - B*(B-1)/2*-1 + B;
    else answer = A*(A-1)/2*-1 + B*(B+1)/2;
    printf("%lld", answer);
}