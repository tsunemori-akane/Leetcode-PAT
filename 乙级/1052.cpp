#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	vector<vector<string>> arr(3);
	for (int i = 0; i < 3; i++) {
		string s;
		getline(cin, s);
		int left= 0, right = 0;
		while (((left = s.find("[", left)) != string::npos) && ((right = s.find("]", right)) != string::npos)) {
			arr[i].push_back(s.substr(left+1, right-left-1));
			s.erase(left, 1);
			s.erase(right-1, 1);
		}
	}
	int n, a, b, c, d, e;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d >> e;
		if (a > arr[0].size() || b > arr[1].size() || c > arr[2].size() || d > arr[1].size()
			 || e > arr[0].size() || a < 1 || b < 1 || c < 1 || d < 1 || e < 1) {
			cout << "Are you kidding me? @\\/@" << endl;
			continue;
		}
		cout << arr[0][a-1] << "(" << arr[1][b-1] << arr[2][c-1] 
			<< arr[1][d-1] << ")" << arr[0][e-1] << endl;
	}
	return 0;
}

