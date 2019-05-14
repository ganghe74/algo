#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k = 0;
    bool light[100], disturbed[101] = {0};
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &light[i]);
    for (int i=1;i<n-1;++i)
        if (!light[i] && light[i-1] && light[i+1]) disturbed[i] = true;
    for (int i=1;i<n-1;++i) {
        if (disturbed[i] && disturbed[i+2]) {
            disturbed[i] = false;
            disturbed[i+2] = false;
            k++;
        }
        if (disturbed[i]) {
            disturbed[i] = false;
            k++;
        }
    }
    printf("%d", k);
}