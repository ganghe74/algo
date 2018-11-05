#include <iostream>
#include <deque>
using namespace std;
int main() {
    int N, M, answer = 0, cnt = 0;
    scanf("%d %d", &N, &M);
    deque<int> toFind;
    for (int i=0;i<M;++i) {
        int temp;
        scanf("%d", &temp);
        toFind.push_back(temp);
    }
    deque<int> dq;
    for (int i=1;i<=N;++i) dq.push_back(i);
    while(!toFind.empty()) {
        if (toFind.front() == dq.front()) {
            if (cnt > dq.size() / 2) cnt = dq.size() - cnt;
            toFind.pop_front();
            dq.pop_front();
            answer += cnt;
            cnt = 0;
        }
        else {
            dq.push_back(dq.front());
            dq.pop_front();
            ++cnt;
        }
    }
    printf("%d", answer);
}