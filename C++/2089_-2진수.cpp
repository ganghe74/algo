#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int N, mod;
	string answer = "";
	cin >> N;
	if (N==0) {
		cout << 0;
		return 0;
	}
	while (N != 1) {
		if (N>0) {
			mod = N % -2;
			N = N / -2;
		}
		else {
			mod = -(N % -2);
			if (mod == 0) N = N / -2;
			else N = N / -2 + 1;
		}
		answer = to_string(mod) + answer;
	}
	answer = "1" + answer;
	cout << answer;
}
