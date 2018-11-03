#include <iostream>
using namespace std;
bool isPrime(int n) {
	bool result = true;
	if (n == 1) result = false; 
	for (int i=2;i*i<=n;++i) {
		if (n%i == 0) result = false;
	}
	return result;
}
int main() {
	int N, x, count = 0;
	cin >> N;
	while (N--) {
		cin >> x;
		if (isPrime(x)) count += 1;
	}
	cout << count;
}
