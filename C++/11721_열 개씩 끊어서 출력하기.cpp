#include <iostream>
int main() {
	int i = 0;
	char str[100];
	scanf("%s", str);
	while (str[i] != 0){
		putchar(str[i]);
		if (i % 10 == 9) putchar('\n');
		i += 1;
	}
}
