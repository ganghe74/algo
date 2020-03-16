#include <bits/stdc++.h>
using namespace std;

const int dr[] = {-1,-1,-1,0,0,1,1,1};
const int dc[] = {-1,0,1,-1,1,-1,0,1};

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> rand_int9(0, 9);
uniform_real_distribution<double> rand_double1(0, 1);

class Chromosome {
public:
    int _score;
    int _surface;
    array<array<int, 14>, 8> table;
    array<bool, 10001> check;
    array<array<array<bool, 10>, 14>, 8> visited;
    Chromosome() : Chromosome({}) {}
    Chromosome(array<array<int, 14>, 8> &table) : _score(-1), _surface(-1), table(table), check({}), visited({}) {}
    void dfs(int r, int c, int depth, int num) {
        check[num] = 1;
        if (depth == 4) return;
        for (int k=0;k<8;++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (0 <= nr && nr < 8 && 0 <= nc && nc < 14) {
                visited[nr][nc][table[r][c]] = 1;
                dfs(nr, nc, depth+1, num*10 + table[nr][nc]);
            }
        }
    }
    void dfs_all() {
        for (int i=0;i<8;++i)
            for (int j=0;j<14;++j)
                dfs(i, j, 1, table[i][j]);
        _score = find(check.begin()+1, check.end(), 0) - check.begin() - 1;
        _surface = 0;
        for (int i=0;i<8;++i)
            for (int j=0;j<14;++j)
                for (int k=0;k<10;++k)
                    _surface += visited[i][j][k];
    }
    int score() {
        if (_score != -1) return _score;
        dfs_all();
        return _score;
    }
    int surface() {
        if (_surface != -1) return _surface;
        dfs_all();
        return _surface;
    }
    int fitness() {
        return score();
        // return score() + surface();
    }
    void clear() {
        _score = _surface = -1;
        check.fill(0);
        for (int i=0;i<8;++i)
            for (int j=0;j<14;++j) visited[i][j].fill(0);
    }
    // TODO
    // I think crossover is meaningless...
    // Or i didn't find good algorithm.
    Chromosome crossover(Chromosome &other) {
        array<array<int, 14>, 8> child_table = table;
        for (int i=0;i<8;++i)
            for (int j=0;j<14;++j)
                if (rand_double1(gen) < 0.5)
                    child_table[i][j] = other.table[i][j];
        return Chromosome(child_table);
    }
    void mutate() {
        clear();
        if (rand_double1(gen) < 0.5) { // random number
            for (int i=0;i<8;++i)
                for (int j=0;j<14;++j)
                    if (rand_double1(gen) < 0.05)
                        table[i][j] = rand_int9(gen);
        }
        if (rand_double1(gen) < 0.5) { // random swap
            while (rand_double1(gen) < 0.7) {
                int r1 = rand_double1(gen) * 8;
                int c1 = rand_double1(gen) * 14;
                int r2 = rand_double1(gen) * 8;
                int c2 = rand_double1(gen) * 14;
                swap(table[r1][c1], table[r2][c2]);
            }
        }
    }
    operator int() {
        return fitness();
    }
};

ostream &operator <<(ostream &out, Chromosome &obj) {
    for (int i=0;i<8;++i) {
        for (int j=0;j<14;++j) out << obj.table[i][j];
        out << endl;
    }
    out << "Fitness: " << obj.fitness() << " (score: " << obj.score() << ", surface: " << obj.surface() << ")" << endl;
    return out;
}

Chromosome get_random_one() {
    array<array<int, 14>, 8> a;
    for (int i=0;i<8;++i)
        for (int j=0;j<14;++j)
            a[i][j] = rand_int9(gen);
    return Chromosome(a);
}
