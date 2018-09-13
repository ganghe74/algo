#include <iostream>
using namespace std;
int main() {
	int N, answer = 0;
	cin >> N;
	for (int i=5;i<=N;i*=5) {
		answer += N/i;
	}
	cout << answer;
}
