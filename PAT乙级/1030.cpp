#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N;
	long long p;
	scanf("%d%lld", &N, &p);
	vector<int> v(N);
	for (int i = 0; i < N; i ++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int result = 0, temp = 0;
	for (int i = 0; i < N ; i++) {
		for (int len = i+result; len < N; len++) {
			if (v[i]*p >= v[len]) {
				temp = result + 1;
				if (temp > result)
					result = temp;
			} else break;
		}
	}
	cout << result;
	return 0;
}
