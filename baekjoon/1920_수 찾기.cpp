#include <iostream>
#include <map>
using namespace std;
int main() {
    int N, M, temp;
    map<int, bool> check;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d", &temp);
        check[temp] = true;
    }
    scanf("%d", &M);
    for (int i=0;i<M;++i) {
        scanf("%d", &temp);
        if (check[temp] == true) printf("1\n");
        else printf("0\n");
    }
}