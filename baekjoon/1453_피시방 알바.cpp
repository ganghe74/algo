#include <iostream>
using namespace std;
bool a[100];
int main() {
    int N, in, deny = 0;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &in);
        if (a[in-1]) deny += 1;
        else a[in-1] = true;
    }
    printf("%d", deny);
}