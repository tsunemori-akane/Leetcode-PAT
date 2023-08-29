#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, n, score;
	cin >> N;
	vector<int> v(N+1);
	for (int i = 0; i < N; i++) {
		cin >> n >> score;
		v[n] = v[n] + score;
	}
	int max = v[1], s = 1;
	for (int i = 2; i <= N ; i++) {
		if (max < v[i]){
			max = v[i];
			s = i;
		}
	}
	cout << s << " " << max;
}
