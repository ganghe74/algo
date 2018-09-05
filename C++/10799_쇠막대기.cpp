#include <iostream>
#include <string>
using namespace std;
int solve(string x) {
	int count = 0;
	int answer = 0;
	for (int i=0;i<x.size();i++){
		if (x[i] == '(') {
			count += 1;
		}
		if (x[i] == ')') {
			if (x[i-1] == '(') {
				count -= 1;
				answer += count;
			}
			else {
				count -= 1;
				answer += 1;
			}
		}
	}
	return answer;
}
int main() {
	string input;
	cin >> input;
	cout << solve(input) << endl;
}
