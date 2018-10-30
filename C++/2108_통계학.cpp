#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    vector<int> a(N);
    int count[10000] = {0};
    for (int i=0;i<N;++i) {
        scanf("%d", &a[i]);
        count[a[i]+5000] += 1;
    }

    int sum=0;
    for (int i=0;i<N;++i) {
        sum += a[i];
    }
    printf("%.0f\n", (double)sum/N);
    
    sort(a.begin(), a.end());
    printf("%d\n", a[N/2]);

    int mode[2] ={0};
    for (int i=0;i<10000;++i) {
        if (count[i] > count[mode[0]]) mode[0] = i;
        else if (count[i] > count[mode[1]]) {
            if (count[mode[0]] <= count[i]) {
                mode[1] = mode[0];
                mode[0] = i;
            }
        }
    }
    printf("%d\n", mode[0]-5000);

    printf("%d\n", a[N-1] - a[0]);
}