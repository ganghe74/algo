#include <stdio.h>
typedef int bool;
#define true 1;
#define false 0;
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