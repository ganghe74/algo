#include <iostream>
using namespace std;
int a[50];
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    if (N == 1) printf("A");
    else if (N == 2) {
        if (a[0] == a[1]) printf("%d", a[0]);
        else printf("A"); 
    }
    else {
        int A, B;
        if (a[0] == a[1]) {
            A = 1; B = 0;
        }
        else {
            A = (a[1]-a[2]) / (a[0]-a[1]);
            B = a[1] - a[0] * A;
        }

        bool c = true;
        for (int i=0;i<N-1;++i) {
            if (a[i] * A + B != a[i+1]) c = false;
        }

        if (c) printf("%d", a[N-1] * A + B);
        else printf("B");
    }
}