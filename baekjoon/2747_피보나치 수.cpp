/*
1.Top down
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
*/



/*
2.Bottom up
#include <iostream>
using namespace std;
int main() {
	int n;
	int fibo[46] = {0,1,1};
	cin >> n;
	for (int i=3;i<=n;++i){
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	cout << fibo[n];
}
*/
