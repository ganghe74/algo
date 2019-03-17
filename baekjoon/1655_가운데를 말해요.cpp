#include <iostream>
#include <queue>
using namespace std;
int main() {
    int N, num;
    scanf("%d", &N);
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    while (N--) {
        scanf("%d", &num);
        if (maxHeap.size() == minHeap.size()) maxHeap.push(num);
        else minHeap.push(num);
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int a = maxHeap.top(), b = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(b);
            minHeap.push(a);
        }
        printf("%d\n", maxHeap.top());
    }
}