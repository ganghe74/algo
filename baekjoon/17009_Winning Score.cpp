#include <iostream>
using namespace std;
int main() {
    int a, b, A = 0, B = 0;
    for (int i=3;i>0;--i) scanf("%d", &a), A += a * i;
    for (int i=3;i>0;--i) scanf("%d", &b), B += b * i;
    if (A == B) printf("T");
    if (A > B) printf("A");
    if (A < B) printf("B");
}