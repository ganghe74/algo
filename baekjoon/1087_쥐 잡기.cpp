#include <bits/stdc++.h>
using namespace std;

int n;
double x[50], y[50], dx[50], dy[50];

double f(double t) {
    double l=0;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            l = max(l, abs(x[i]+dx[i]*t - x[j]-dx[j]*t));
            l = max(l, abs(y[i]+dy[i]*t - y[j]-dy[j]*t));
        }
    }
    return l;
}

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;++i)
        scanf("%lf%lf%lf%lf", &x[i], &y[i], &dx[i], &dy[i]);
    double t=0;
    double dt=2000;
    while (dt > 0) {
        if (t-dt >= 0 && f(t-dt) < f(t)) t -= dt;
        else if (f(t+dt) < f(t)) t += dt;
        dt /= 2;
    }
    printf("%.11lf", f(t));
}
