#include <iostream>
using namespace std;
int cnt[128];
int main() {
    char ch;
    while ((ch = getchar()) != EOF) {
        cnt[ch]++;
    }
    int most = 0;
    for (int i='a';i<='z';++i) {
        most = max(most, cnt[i]);
    }
    for (int i='a';i<='z';++i) {
        if (cnt[i] == most) putchar(i);
    }
}