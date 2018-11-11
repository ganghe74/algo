#include <iostream>
#include <vector>
#include <cstring>
#define max(a,b) ((a>b)?a:b)
using namespace std;

int N;
int d[501];
vector<int> a;

int lis(int start) {
    int &ret = d[start+1];
    if (ret != -1) return ret;
    ret = 1;
    for (int next = start+1;next<N;++next) {
        if(start == -1 || a[start] < a[next]) ret = max(ret, lis(next) + 1);
    }
    return ret;
}

int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        memset(d, -1, sizeof(d));
        scanf("%d", &N);
        for (int i=0;i<N;++i) {
            int temp;
            scanf("%d", &temp);
            a.push_back(temp);
        }
        printf("%d\n", lis(-1)-1);
        a.clear();
    }
}