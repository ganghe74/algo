#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int main() {
	int N, n;
	cin >> N;
	vector<int> x;
	while (N--) {
		cin >> n;
		x.push_back(n);
	}
	sort(x.begin(),x.end());
	for (auto &n : x) {
		cout << n << endl;
	}
}
