#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> plus;
    vector<int> minus;
    int N;
    int zero = 0, one = 0;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        int temp;
        scanf("%d", &temp);
        if (temp == 0) zero += 1;
        else if (temp == 1) one += 1;
        else if (temp > 0) plus.push_back(temp);
        else minus.push_back(temp); 
    }
    sort(plus.begin(), plus.end());
    reverse(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    int answer = one;
    if (plus.size() % 2 == 1) plus.push_back(1);
    for (int i=0;i<plus.size();i+=2) {
        answer += plus[i] * plus[i+1];
    }
    if (minus.size() % 2 == 1) {
        if (zero > 0) minus.push_back(0);
        else minus.push_back(1);
    }
    for (int i=0;i<minus.size();i+=2) {
        answer += minus[i] * minus[i+1];
    }
    printf("%d", answer);
}