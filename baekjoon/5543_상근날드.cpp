#include <iostream>
using namespace std;
int main() {
    int burger = 2000, beverage = 2000, temp;
    for (int i=0;i<3;++i) {
        scanf("%d", &temp);
        if (temp < burger) burger = temp;
    }
    for (int i=0;i<2;++i) {
        scanf("%d", &temp);
        if (temp < beverage) beverage = temp;
    }
    printf("%d", burger + beverage - 50);
}