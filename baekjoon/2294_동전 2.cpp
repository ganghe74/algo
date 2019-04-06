#include <iostream>
#include <set>
using namespace std;
set<int> s;
int d[100001];
int main() {
    int n, k, num;
    scanf("%d%d", &n, &k);
    while (n--) {
        scanf("%d", &num);
        s.insert(num);
    }
    for (int i=0;i<=10000;++i) d[i] = 10001;
    d[0] = 0;
    for (int i=0;i<=k;++i) {
        for (int value : s) {
            if (i >= value) {
                if (d[i] == 0) d[i] = 10000;
                d[i] = min(d[i-value]+1, d[i]);
            }
        }
    }
    if (d[k] == 10001) printf("-1"); 
    else printf("%d", d[k]);
}