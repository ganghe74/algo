#include <iostream>
using namespace std;
int R[405][405], G[405][405], B[405][405];
int main() {
    int N, M;
    cin >> N >> M;
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            cin >> R[i][j] >> G[i][j] >> B[i][j];
        }
    }
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            int I = 2126 * R[i][j] + 7152 * G[i][j] + 722 * B[i][j];
            if (I >= 2040000) cout << '.';
            else if (I >= 1530000) cout << '-';
            else if (I >= 1020000) cout << '+';
            else if (I >= 510000) cout << 'o';
            else if (I >= 0) cout << '#';
        }
        cout << '\n';
    }
}