#include <iostream>
using namespace std;
int main() {
    char x[1000005] = ".";
    long long answer = 1;
    scanf("%s", x+1);
    for (int i=1;x[i]!='\0';++i) {
        int gob = 1;
        if (x[i] == 'c') gob = 26;
        else if (x[i] == 'd') gob = 10;
        if (x[i] == x[i-1]) gob--;
        answer *= gob;
        answer %= 1000000009;
    }
    printf("%lld", answer);
}