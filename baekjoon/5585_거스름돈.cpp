#include <iostream>
using namespace std;
int main() {
    int a[6] = {500, 100, 50, 10, 5, 1};
    int price, cnt = 0;
    scanf("%d", &price);
    price = 1000 - price;
    for (int i=0;i<6;++i) {
        while (a[i] <= price) {
            price -= a[i];
            cnt++;
        }
    }
    printf("%d", cnt);
}