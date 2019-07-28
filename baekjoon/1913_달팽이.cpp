#include <bits/stdc++.h>
using namespace std;

int a[1005][1005];
void f (int pos, int size, int num) {
    for (int i=0;i<size;++i) a[pos+i][pos] = num--;
    for (int i=1;i<size;++i) a[pos+size-1][pos+i] = num--;
    for (int i=size-2;i>=0;--i) a[pos+i][pos+size-1] = num--;
    for (int i=size-2;i>0;--i) a[pos][pos+i] = num--;
}

int main() {
    int n, target;
    scanf("%d%d", &n, &target);
    for (int i=n;i>0;i-=2) {
        f((n-i)/2, i, i*i);
    }
    pair<int,int> pi;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            if (a[i][j] == target) pi = {i+1, j+1};
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    printf("%d %d", pi.first, pi.second);
}