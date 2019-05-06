#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// void print(queue<int> q, stack<int> wait) {
//     printf("Q : ");
//     while (!q.empty()) {
//         printf("%d ", q.front());
//         q.pop();
//     }
//     printf("\nwait : ");
//     while (!wait.empty()) {
//         printf("%d ", wait.top());
//         wait.pop();
//     }
//     printf("\n\n");
// }

int main() {
    int N, num;
    char alpha;
    queue<int> q;
    vector<int> order;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<5;++j) {
            scanf(" %c-%d", &alpha, &num);
            num = (alpha - 'A') * 1000 + num;
            q.push(num);
            order.push_back(num);
        }
    }

    int idx = 0;
    sort(order.begin(), order.end());
    stack<int> wait;

    while (!q.empty()) {
        if (!wait.empty()) {
            while (wait.top() == order[idx]) {
                wait.pop();
                idx++;
                if (wait.empty()) break;
            }
        }
        if (q.front() == order[idx]) idx++;
        else wait.push(q.front());
        q.pop();
        //print(q, wait);
    }

    while (!wait.empty()) {
        if (wait.top() != order[idx]) {
            puts("BAD");
            return 0;
        }
        idx++;
        wait.pop();
        //print(q, wait);
    }
    puts("GOOD");
}