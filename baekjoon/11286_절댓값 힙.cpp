#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
int cmp(int a, int b) {
    if (abs(a) == abs(b)) return a < b;
    return abs(a) < abs(b);
}
void push(int x) {
    heap.push_back(x);
    int idx = heap.size() - 1;
    while (idx > 0 && cmp(heap[idx], heap[(idx-1)/2])) {
        swap(heap[idx], heap[(idx-1)/2]);
        idx = (idx - 1) / 2;
    }
}
int pop() {
    if (heap.empty()) return 0;
    int ret = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    int here = 0;
    while (true) {
        int left = here * 2 + 1, right = here * 2 + 2;
        if (left >= heap.size()) break;
        int next = here;
        if (cmp(heap[left], heap[next]))
            next = left;
        if (right < heap.size() && cmp(heap[right], heap[next]))
            next = right;
        if (next == here) break;
        swap(heap[here], heap[next]);
        here = next;
    }
    return ret;
}
int main() {
    int N, x;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &x);
        if (x == 0) printf("%d\n", pop());
        else push(x);
    }
}