#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        string op;
        cin >> op;
        scanf("%d", &n);
        deque<int> dq(n);
        scanf("%d", &n);
        scanf("[%d", &dq[0]);
        for (int i=1;i<n;++i) {
            scanf(",%d", &dq[i]);
        }
        scanf("]");
        bool R = false;
        for (auto x:op) {
            if (dq.size() == -1) break;
            if (x=='R') R = !R;
            else if (x=='D') {
                if(R) dq.pop_back();
                else dq.pop_front();
            }
        }
        if (dq.size() == -1) {
            printf("error\n");
            continue;
        }
        if (dq.empty()) {
            printf("[]\n");
            continue;
        }
        if (R) reverse(dq.begin(), dq.end());
        printf("[");
        for (int i=0;i<dq.size()-1;++i) printf("%d,",dq[i]);
        printf("%d]\n",dq.back());
    }
}