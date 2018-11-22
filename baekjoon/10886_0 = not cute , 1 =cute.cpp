#include <iostream>
using namespace std;
int main() {
    int N, in;
    int yes = 0;
    int no = 0;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &in);
        if (in) yes += 1;
        else no += 1;
    }
    if (yes > no) printf("Junhee is cute!");
    else printf("Junhee is not cute!");
}