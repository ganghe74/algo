#include <iostream>
using namespace std;
int main() {
	int N, answer = 0;
	cin >> N;
	for (int i=5;i<=N;i+=5) {
		int temp = i;
		while (temp % 5 == 0) {
			answer += 1;
			temp = temp / 5;
		}
	}
	cout << answer;
}
