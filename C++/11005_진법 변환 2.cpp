#include <iostream>
#include <string>
using namespace std;
int main() {
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string answer = "";
	int N, B, mod;
	cin >> N >> B;
	while (N != 0) {
		mod = N % B;
		N = N / B;
		if (mod < 10) answer += to_string(mod);
		else answer += alphabet[mod-10];
		cout << answer << endl;
	}
	for (int i=answer.size()-1; i>=0; --i) {
		cout << answer[i];
	}
	cout << alphabet[0];
}
