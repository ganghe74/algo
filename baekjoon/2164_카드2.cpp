#include <iostream>
#include <queue>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    queue<int> card;
    for (int i=1;i<=N;++i) card.push(i);
    while (card.size() > 1) {
        card.pop();
        card.push(card.front());
        card.pop();
    }
    printf("%d", card.front());
}