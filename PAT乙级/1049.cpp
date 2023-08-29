#include<iostream>

using namespace std;
/*
**1     2    3   4  5
**12    23   34  45
**123   234  345
**1234  2345
**12345 
**可以发现数字1有1列每列5个，数字2有2列每列4个，数字3有3列每列3个，数字4有4列每列2个，数字5有5列每列1个，类推即可
*/
int main() {
	int N;
	cin >> N;
	double f, result = 0.00;
	for (int i = N, j = 1; i > 0; i--, j++) {
		cin >> f;
		result += f*i*j;
	}
	printf("%.2f", result);
	return 0;
}