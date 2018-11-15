#include <iostream>
#define min(a,b) ((a<b)?a:b)
using namespace std;
int main() {
    int x, y, w, h, answer;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    answer = min(x, w-x);
    answer = min(answer, y);
    answer = min(answer, h-y);
    printf("%d", answer);
}