#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
	string word;
	vector<string> words;
	cin >> word;
	for (int i=0;i<word.size();i++) {
		words.push_back(word.substr(i,word.size()-i));
	}
	sort(words.begin(), words.end());
	for (auto &n : words) {
		cout << n << endl;
	}
}
