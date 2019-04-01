#include <iostream>
using namespace std;
int main() {
    int S1, S2, ans, input;
    scanf("%d%d", &S1, &S2);
    while (S1--) {
        scanf("%d%d", &ans, &input);
        if (ans != input) {
            puts("Wrong Answer");
            return 0;
        }
    }
    while (S2--) {
        scanf("%d%d", &ans, &input);
        if (ans != input) {
            puts("Why Wrong!!!");
            return 0;
        }
    }
    puts("Accepted");
}