#include <iostream>
using namespace std;
int main() {
    bool star = true;
    int N;
    scanf("%d", &N);
    for (int i=0;i<2*N;++i) {
        for (int j=0;j<N;++j)  {
            if (star) putchar('*');
            else putchar(' ');
            star = !star;
        }
        if (N%2==0) star = !star;
        puts("");
    }
}