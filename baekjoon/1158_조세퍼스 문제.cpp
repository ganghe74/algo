#include <iostream>
#include <queue>
using namespace std;
int main() {
	int N, M, temp;
	cin >> N >> M;
	queue<int> people;
	for (int i=1;i<=N;i++) {
		people.push(i);
	}
	cout << '<';
	for (int i=0;i<N;i++) {
		for (int j=0;j<M-1;j++) {
			people.push(people.front());
			people.pop();
		}
		cout << people.front();
		people.pop();
		if (!people.empty()) {
			cout << ", ";
		}
	}
	cout << '>'; 
}
