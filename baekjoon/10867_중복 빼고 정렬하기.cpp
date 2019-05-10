#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> s;
    int N, num;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &num);
        s.insert(num);
    }
    for (auto x : s) {
        printf("%d ", x);
    }
}