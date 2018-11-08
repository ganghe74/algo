#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n ;
    scanf("%d", &n);
    while (n != -1) {
        int sum = 1;;
        vector<int> divisors;
        for (int i=2;i<n;++i) {
            if (n%i == 0) {
                sum += i;
                divisors.push_back(i);
            }
        }
        if (sum != n) printf("%d is NOT perfect.", n);
        else {
            printf("%d = 1", sum);
            for (auto x : divisors) {
                printf(" + %d", x);
            }
        }
        printf("\n");
        scanf("%d", &n);
    }
}