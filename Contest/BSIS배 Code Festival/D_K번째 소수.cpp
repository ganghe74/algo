#include <iostream>
#include <vector>
#define MAX 8000000
using namespace std;
int main() {
	int K;
	cin >> K;
	int cnt = 0;
	vector<bool> prime(MAX,0);
	for (int i=2;i<MAX;++i) {
		if (prime[i] == 0) {
			for (int j=2;i*j<MAX;++j) {
				prime[i*j] = 1;
			}
			cnt += 1;
			if (cnt == K) {
				cout << i;
				return 0;
			}
		}
	}
}
