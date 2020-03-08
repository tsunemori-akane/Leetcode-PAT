/*
**inspired by liuchuo
*/
#include<iostream>

using namespace std;

int main() {
	int n, draw=0, failA=0, failB=0;
	int winA[3] = {0}, winB[3] = {0};
	char a, b;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a >> b;
		if (a == b == ('J' || 'C' || 'B')) draw ++;
		if (a == 'C' && b == 'J') {
			winA[1]++;
			failB++;
		}
		if (a == 'J' && b == 'B') {
			winA[2]++;
			failB++;
		}
		if (a == 'B' && b == 'C') {
			winA[0]++;
			failB++;
		}
		if (b == 'C' && a == 'J') {
			winB[1]++;
			failA++;
		}
		if (b == 'J' && a == 'B') {
			winB[2]++;
			failA++;
		}
		if (b == 'B' && a == 'C') {
			winB[0]++;
			failA++;
		}
	}
		cout << winA[0]+winA[1]+winA[2] << " " << draw << " " << failA << endl;
		cout << winB[0]+winB[1]+winB[2] << " " << draw << " " << failB << endl;
		int maxA = winA[0] >= winA[1] ? 0 : 1;
		maxA = winA[maxA] >= winA[2] ? maxA : 2;
		int maxB = winB[0] >= winB[1] ? 0 : 1;
		maxB = winB[maxB] >= winB[2] ? maxB : 2;
		char BCJ[3] = {'B', 'C', 'J'};
		cout << BCJ[maxA] << " " << BCJ[maxB];
	
	return 0;
}
