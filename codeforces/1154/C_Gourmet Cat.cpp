#include <iostream>
using namespace std;
int main() {
    int rotation[7] = {0, 1, 2, 0, 2, 1, 0};
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int week = min(a/3, min(b/2, c/2));
    a -= 3 * week, b -= 2 * week, c -= 2 * week;
    int max_eat = 0;
    for (int i=0;i<7;++i) {
        int aa[3] = {a, b, c};
        int day = i, cnt = 0;
        while (aa[rotation[day]] != 0) {
            aa[rotation[day]]--;
            cnt++;
            day = (day + 1) % 7;
        }
        max_eat = max(max_eat, cnt);
    }
    printf("%d", week * 7 + max_eat);
}