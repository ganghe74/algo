#include <iostream>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    if (N%2==0) printf("I LOVE CBNU");
    else {
        for (int i=0;i<N;++i) printf("*");
        printf("\n");
        for (int i=0;i<N/2;++i) printf(" ");
        printf("*\n");
        int blankA = N/2-1;
        int blankB = 1;
        while (blankA >= 0) {
            for (int i=0;i<blankA;++i) printf(" ");
            printf("*");
            for (int i=0;i<blankB;++i) printf(" ");
            printf("*\n");
            blankA--;
            blankB += 2;
        }
    }
}