#include <iostream>
#include <string.h>
using namespace std;
int main() {
	char bin[8][4] = {"000","001", "010", "011", "100", "101", "110", "111"};
	char a[333336];
	scanf("%s", a);
	int length = strlen(a);
	if (a[0] < '2') printf("%c",bin[a[0]-'0'][2]);
	else if(a[0] < '4') printf("%c%c",bin[a[0]-'0'][1],bin[a[0]-'0'][2]);
	else printf("%s", bin[a[0]-'0']);
	for (int i=1;i<length;++i) {
		printf("%s",bin[a[i]-'0']);
	}
}
