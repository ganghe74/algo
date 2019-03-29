#include <iostream>
#include <map>
using namespace std;
int main() {
    map<int, int> m;
    m[0] += 1;
    printf("%d\n", m[0]);

    m[0] = 0;

    cout << m.begin()->first;   
}