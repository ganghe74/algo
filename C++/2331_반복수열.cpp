#include <iostream>
using namespace std;
int check[1000000] = {0};

int pow(int x, int p) {
    int answer = 1;
    while (p--) {
        answer = answer * x;
    }
    return answer;
}

int next(int a,int p) {
    int answer = 0;
    while (a>0) {
        answer += pow(a%10, p);
        a /= 10;
    }
    return answer;
}

int length(int a, int p, int cnt) {
    if (check[a] != 0) return check[a] - 1;
    check[a] = cnt;
    a = next(a, p);
    return length(a, p, cnt+1);
}

int main() {
    int A, P;
    cin >> A >> P;
    cout << length(A, P, 1);
}