#include<iostream>

using namespace std;

int main() {
	int n, D, k, perhaps = 0, empty = 0;
	double e, E;
	cin >> n >> e >> D;
	for (int i = 0; i < n; i++) {
		cin >> k;
		int sum = 0;
		for (int j = 0; j < k;j++) {
			cin >> E;
			if (E < e) sum++;
		}
		if (k > D && sum > k/2) empty ++;
		else if(sum > k/2) perhaps ++;
	}
	printf("%.1f%% %.1f%%", double(perhaps)/n*100, double(empty)/n*100);
}
