#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main() {
    vector<int> A, B;
    char s[10005];
    scanf("%s", s);
    for (int i=strlen(s)-1;i>=0;--i) A.push_back(s[i]-'0');
    scanf("%s", s);
    for (int i=strlen(s)-1;i>=0;--i) B.push_back(s[i]-'0');

    while (A.size() != B.size()) {
        if (A.size() > B.size()) B.push_back(0);
        else A.push_back(0);
    }
    A.push_back(0);

    for (int i=0;i<B.size();++i) {
        A[i] = A[i] + B[i];
        if (A[i] > 9) {
            A[i] -= 10;
            A[i+1]++;
        }
    }
    
    if (A[A.size()-1] > 0) printf("%d", A[A.size()-1]);
    for (int i = A.size()-2;i>=0;--i) printf("%d", A[i]);
}