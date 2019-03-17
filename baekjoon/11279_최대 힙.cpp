#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    priority_queue<int, vector<int>, less<>> maxHeap;
    int N, x;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &x);
        if (x == 0) {
            if (maxHeap.empty()) puts("0");
            else {
                printf("%d\n", maxHeap.top());
                maxHeap.pop();
            }
        }
        else maxHeap.push(x);
    }
}