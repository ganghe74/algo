#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> board;

const int coverType[4][3][2] = {
    { {0,0}, {1,0}, {0,1} },
    { {0,0}, {0,1}, {1,1} },
    { {0,0}, {1,0}, {1,1} },
    { {0,0}, {1,0}, {1,-1} }
};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
    bool ok = true;
    for (int k=0;k<3;++k) {
        const int ny = y + coverType[type][k][0];
        const int nx = x + coverType[type][k][1];
        if (ny < 0 || ny >= board.size() || nx < 0 || nx >=board[0].size()) ok = false;
        else if((board[ny][nx] += delta) > 1) ok = false;
    }
    return ok;
}

int cover(vector<vector<int>> &board) {
    int y = -1, x = -1;
    for (int i=0;i<board.size();++i) {
        for (int j=0;j<board[0].size();++j) {
            if (!board[i][j]) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }
    if (y == -1) return 1;
    int cnt = 0;
    for (int k=0;k<4;++k) {
        if (set(board,y,x,k,1)) {
            cnt += cover(board);
        }
        set(board,y,x,k,-1);
    }
    return cnt;
}

int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
    
        int H, W;
        scanf("%d %d", &H, &W);
        for (int i=0;i<H;++i) {
            vector<int> a;
            for (int j=0;j<W;++j) {
                char temp;
                scanf("\n%c", &temp);
                if (temp == '#') a.push_back(1);
                else a.push_back(0);
            }
            board.push_back(a);
        }

        for (vector<int> vec: board) {
            for (int n : vec) {
                cout << n;
            }
            cout << endl;
        }

        printf("%d\n", cover(board));

        board.clear();
    }
}