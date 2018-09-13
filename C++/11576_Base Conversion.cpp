#include <iostream>
#include <stack>
using namespace std;
int main() {
	int A, B, m, temp, sum = 0;
	cin >> A >> B;
	cin >> m;
	while (m--) {
		cin >> temp;
		sum = sum * A + temp;
	}
	stack<int> answer;
	while (sum >= B) {
		answer.push(sum%B);
		sum = sum / B;
	}
	answer.push(sum); 
	
	while (!answer.empty()) {
		cout << answer.top() << " ";
		answer.pop();
	}
}
