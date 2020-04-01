#include<iostream>

using namespace std;

int main() {
	int N, num, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		sum += (N-1) * num + (N-1) * num * 10;
	}
	cout << sum ;
	return 0;
}
