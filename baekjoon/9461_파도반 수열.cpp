#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T; 
	long long d[100] = {1,1,1,2,2};
	for (int i=5;i<101;++i) {
		d[i] = d[i-1] + d[i-5];
	}
	while (T--) {
		int N;
		cin >> N;
		cout << d[N-1] << endl;
	}
}
