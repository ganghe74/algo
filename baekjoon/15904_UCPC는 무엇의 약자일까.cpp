#include <iostream>
using namespace std;
int main() {
    char s[1001];
    cin.getline(s, 1000);
    int i = 0, find = 0;
    while (s[i] != '\0') {
        if (s[i++] == "UCPC"[find]) find++;
    }
    if (find == 4) printf("I love UCPC");
    else printf("I hate UCPC");
}