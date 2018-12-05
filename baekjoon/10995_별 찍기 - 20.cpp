#include <iostream>
using namespace std;
int main() {
    int N;
    bool space = false;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        if (space) printf(" ");
        for (int j=0;j<N;++j) printf("* ");
        printf("\n");
        space = !space;
    }
}