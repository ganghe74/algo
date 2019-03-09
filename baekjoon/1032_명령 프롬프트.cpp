#include <iostream>
using namespace std;
int main() {
    int N, size = 0;
    scanf("%d", &N);
    char words[N][51];
    for (int i=0;i<N;++i) scanf("%s", words[i]);
    while (words[0][++size] != '\0');
    char answer[size+1];
    answer[size] = '\0';
    for (int i=0;i<size;++i) {
        answer[i] = words[0][i];
        for (int j=0;j<N;++j) {
            if (answer[i] != words[j][i]) answer[i] = '?';
        }
    }
    printf("%s", answer);
}