#include <iostream>
#include <map>
using namespace std;
int main() {
    int a[200005];
    map<int,int> m;
    int n, num;
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    for (int i=0;i<n;++i) {
        scanf("%d", &num);
        m[num]++;
    }

    for (int i=0;i<n;++i) {
        int b1, b2;
        if (m.lower_bound(n-a[i]) == m.end()) b1 = n - a[i] - 1;
        else b1 = (*m.lower_bound(n-a[i])).first;
        b2 = (*m.lower_bound(0)).first;

        if ((a[i] + b1) % n < (a[i] + b2) % n) {
            printf("%d ", (a[i] + b1) % n);
            m[b1]--;
            if (m[b1] == 0) m.erase(b1);
        }
        else {
            printf("%d ", (a[i] + b2) % n);
            m[b2]--;
            if (m[b2] == 0) m.erase(b2);
        }
    }
}