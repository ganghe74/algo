#include <bits/stdc++.h>
using namespace std;
int calculate(vector<int> a) {
    int sum = 0;
    for (int i=0;i<a.size()-1;++i) {
        sum += abs(a[i] - a[i+1]);
    }
    return sum;
}
int main() {
    int N, answer = 0;
    scanf("%d", &N);
    vector<int> a(N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    do {
        int sum = calculate(a);
        if (sum > answer) answer = sum;
    } while (next_permutation(a.begin(), a.end()));
    printf("%d", answer);
}