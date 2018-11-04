// 시간초과..
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

void normalize(vector<int>& num) {
    num.push_back(0);
    for (int i=0;i<num.size()-1;++i) {
        if (num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= borrow;
            num[i] += borrow * 10;
        }
        else {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while(num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i=0;i<a.size();++i) {
        for (int j=0;j<b.size();++j) {
            c[i+j] += a[i] * b[j];
        }
    }
    normalize(c);
    return c;
}

int hugs(const string& members, const string& fans) {
    int N = members.size(), M = fans.size();
    vector<int> A(N), B(M);
    for (int i=0;i<N;++i) A[i] = (members[i] == 'M');
    for (int i=0;i<M;++i) B[M-i-1] = (fans[i] == 'M');
    vector<int> C = karatsuba(A, B);
    int allHugs = 0;
    for (int i=N-1;i<M;++i) {
        if(C[i] == 0) ++ allHugs;
    }
    return allHugs;
}

int main() {
    int C;
    scanf("%d", &C);
    while(C--) {
        string a,b;
        char temp[200001];
        scanf("%s", &temp);
        a = temp;
        scanf("%s", &temp);
        b = temp;
        printf("%d\n", hugs(a,b));
    }
}