#include <bits/stdc++.h>
using namespace std;
int main() {
    int K, scan;
    stack<int> s;
    scanf("%d", &K);
    for (int i=0;i<K;++i) {
        scanf("%d", &scan);
        if (scan == 0) s.pop();
        else s.push(scan);
    }
    int answer = 0;
    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }
    printf("%d", answer);
}