#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[10000];
bool compare(int a, int b) {
	return a > b;
}
int main() {
	int n, c, flag = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> c;
		v[i] = c;
		while (c != 1) {
			if (c % 2 == 1) c = 3*c+1;
			c = c/2;
			if (arr[c] == 1) break;
			arr[c] = 1;
		}
	}
	sort(v.begin(), v.end(), compare);
	for(int i = 0; i < n; i++) {
		if (arr[v[i]] == 0) {
			if (flag == 1) cout << " " ;
			cout << v[i];
			flag = 1;
		}
	}
	return 0;
}