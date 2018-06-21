#include <iostream>
int main() {
	int i, x, y, total_day = 0;
	char a[7][4] = { "MON" ,"TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	int day_list[11] = {31,28,31,30,31,30,31,31,30,31,30};
	scanf("%d %d", &x, &y);
	for (i=0;i<x-1;i++){
		total_day += day_list[i];
	}
	total_day += y - 1;
	
	printf("%d %d\n",total_day, total_day % 7);
	printf("%s", a[total_day%7]);
}
