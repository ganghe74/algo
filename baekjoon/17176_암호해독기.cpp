#include <iostream>
using namespace std;
int a[53];
int main() {
    int N, code;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &code);
        a[code]++;
    }
    getchar();
    for (int i=0;i<N;++i) {
        code = getchar();
        if (code == ' ') code = 0;
        else if (code <= 'Z') code = code - 'A' + 1;
        else code = code - 'a' + 27;
        if (a[code] == 0) {
            puts("n");
            return 0;
        }
        a[code]--;
    }
    puts("y");
}