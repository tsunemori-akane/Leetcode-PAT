#include<iostream>

using namespace std;

int main() {
	int n, teamId, teamMateId, score, a[1001] = {0};
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d-%d %d",&teamId, &teamMateId, &score);
		a[teamId] += score;
	}
	int temp = 0, max = 1;
	for (int i = 1; i < 1001; i++) {
		if(a[i] > temp) {
			temp = a[i];
			max = i;
		}
	}
	cout << max << " " << temp;
	return 0;
}
