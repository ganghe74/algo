#include <iostream>
using namespace std;
int memo[46];
int fibonacci(int n) {
	if (n <= 1) return n;
	else if (memo[n] > 0) {
		return memo[n]; 
	}
	else {
		memo[n] = fibonacci(n-1) + fibonacci(n-2);
		return memo[n];
	}
}
int main() {
	int x;
	cin >> x;
	cout << fibonacci(x);
}
