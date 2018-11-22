#include <bits/stdc++.h>
using namespace std;
int main() {
    string A, B;
    cin >> A >> B;
    if (A.size() > B.size()) {
        while (A.size() != B.size()) {
            B = "0" + B;
        }
    }
    if (A.size() < B.size()) {
        while (A.size() != B.size()) {
            A = "0" + A;
        }
    }
    for (int i=0;i<A.size();++i) {
        cout << A[i] + B[i] - '0' * 2;
    }
}