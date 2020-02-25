#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, A, A1=0, A2=0, A5=0;
	double A4 = 0.0;
	vector<vector<int>> v(5);
	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> A;
		v[A%5].push_back(A);
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0;j < v[i].size(); j++) {
			if (i == 0 && v[0][j] % 2 == 0) A1 += v[0][j];
			if (i == 1 && j % 2 == 0) A2 += v[1][j];
			if (i == 1 && j % 2 == 1) A2 -= v[1][j];
			if (i == 3) A4 += v[3][j];
			if (i == 4 && v[4][j] > A5) A5 = v[4][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		if (i != 0) cout << " ";
		if (i == 0 && A1 == 0 || i != 0 && v[i].size() == 0) {
			cout << "N";
			continue;
		}

		if (i == 0) cout << A1;
		if (i == 1) cout << A2;
		if (i == 2) cout << v[2].size();
		if (i == 3) printf("%.1f", A4/v[3].size());
		if (i == 4) cout << A5;
	}
	return 0;
}
