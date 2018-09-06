#include <iostream>
#include <string>
using namespace std;
int main() {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string word;
	int count = 0;
	cin >> word;
	for (int i=0;i<26;i++) {
		for (auto &x : word) {
			if (x == alphabet[i]) {
				count += 1;
			}
		}
		cout << count << ' ';
		count = 0;
	}
}
