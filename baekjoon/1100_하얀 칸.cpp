#include <iostream>
using namespace std;
int main() {
    int cnt = 0;
    bool white = true;
    for (int i=0;i<8;++i) {
        for (int j=0;j<8;++j) {
            char x = getchar();
            if (x == 'F' && white) cnt++;
            white = !white;
        }
        white = !white;
        getchar();
    }
    printf("%d", cnt);
}