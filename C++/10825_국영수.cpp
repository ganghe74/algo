#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct student {
	int Korean, English, Math;
	string Name;
	bool operator < (const student &v) const {
		if (Korean == v.Korean) {
			if (English == v.English) {
				if (Math == v.Math) return Name < v.Name;
				return Math > v.Math;
			}
			return English < v.English;
		}
		else return Korean > v.Korean;
	}
};
int main() {
	int N;
	cin >> N;
	vector<student> a(N);
	for (int i=0;i<N;++i) {
		cin >> a[i].Name >> a[i].Korean >> a[i].English >> a[i].Math;
	}
	sort(a.begin(), a.end());
	for (int i=0;i<N;++i) {
		cout << a[i].Name << endl;
	}
}
