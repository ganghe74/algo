#include <iostream>
#include <queue>
using namespace std;
int C, N, a, b;
struct RNG {
    int seed;
    RNG() : seed(1983) {}
    int next() {
        int ret = seed;
        seed = ((long long)seed * a + b) % 20090711;
        return ret;
    }
};
int main() {
    scanf("%d", &C);
    while (C--) {
        scanf("%d%d%d", &N, &a, &b);
        RNG rng;
        priority_queue<int, vector<int>, less<int>> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        int sum = 0;
        for (int cnt=1;cnt<=N;++cnt) {
            if (maxHeap.size() == minHeap.size())
                maxHeap.push(rng.next());
            else
                minHeap.push(rng.next());
            if(!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
                int t1 = maxHeap.top(), t2 = minHeap.top();
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(t2);
                minHeap.push(t1);
            }
            sum = (sum + maxHeap.top()) % 20090711;
        }
        printf("%d\n", sum);
    }
}