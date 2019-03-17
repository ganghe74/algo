#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    priority_queue<int, vector<int>, greater<>> minHeap;
    int N, x;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &x);
        if (x == 0) {
            if (minHeap.empty()) puts("0");
            else {
                printf("%d\n", minHeap.top());
                minHeap.pop();
            }
        }
        else minHeap.push(x);
    }
}