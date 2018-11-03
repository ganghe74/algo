#include <iostream>
using namespace std;
int main() {
	int N, temp;
	cin >> N;
	int cnt[10001] = {0};
	while (N--) {
		cin >> temp;
		cnt[temp] += 1;
	}
	for (int i=1;i<=10000;++i) {
		if (cnt[i] > 0) {
			while (cnt[i]--) {
				cout << i << '\n';
			}
		}
	}
}
