#include <bits/stdc++.h>
using namespace std;

int main() {
    char x;
    bool one;
    int sum = 0;
    for (int i=0;i<13;++i) {
        x = getchar();
        if (x == '*') one = (i%2 == 0) ? true : false;
        else {
            if (i % 2) sum += (x - '0') * 3;
            else sum += x - '0';
        }
    }
    for (int i=0;i<10;++i) {
        if (one) {
            if ((sum + i) % 10 == 0) printf("%d", i);
        }
        else {
            if ((sum + 3*i) % 10 == 0) printf("%d", i);
        }
    }
}