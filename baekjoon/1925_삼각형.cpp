#include <iostream>
#include <algorithm>
#define f(x) (x)*(x)
using namespace std;
int main() {
    int x[3], y[3];
    for (int i=0;i<3;++i) cin >> x[i] >> y[i];
    double slope[2];
    for (int i=0;i<2;++i) {
        if (x[i] == x[i+1]) slope[i] = 1e10;
        else slope[i] = ((double)(y[i]-y[i+1]))/(x[i]-x[i+1]);
    }
    if (slope[0] == slope[1]) cout << 'X';
    else {
        int a[3];
        for (int i=0;i<3;++i) a[i] = f(x[i]-x[(i+1)%3]) + f(y[i]-y[(i+1)%3]);
        sort(a, a+3);
        if (a[0] == a[1] && a[1] == a[2]) cout << "Jung";
        else {
            if (a[0] + a[1] == a[2]) cout << "Jikkak";
            else if (a[0] + a[1] < a[2]) cout << "Dunkak";
            else cout << "Yeahkak";
            if (a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) cout << 2;
        }
        cout << "Triangle";
    }
}