#include <iostream>
#include <set>
using namespace std;
int main() {
    char x;
    while (true) {
        set<char> c;
        x = getchar();
        if (x == '#') break;
        while (x != '\n') {
            if (x >= 97) x -= 32;
            if (65 <= x && x <= 90) c.insert(x);
            x = getchar();
        }
        printf("%d\n", c.size());
    }
}