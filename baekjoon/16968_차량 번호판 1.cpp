#include <iostream>
using namespace std;
int main() {
    char x[6] = ".";
    int answer = 1;
    scanf("%s", x+1);
    for (int i=1;x[i]!='\0';++i) {
        int gob;
        if (x[i] == 'c') gob = 26;
        else if (x[i] == 'd') gob = 10;
        if (x[i] == x[i-1]) gob--;
        answer *= gob;
    }
    printf("%d", answer);
}