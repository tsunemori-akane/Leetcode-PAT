#include<iostream>

using namespace std;

bool isPrime(int t) {
    if (t == 1) return false;
	if (t == 2 || t == 3) return true;

	for (int i = 2; i*i <= t; i++) {
		if (t % i == 0) 
			return false;
	}
	return true;
}

int main() {
	int N, i = 3, count = 0;
	cin >> N;
	while (i <= N) {
		if (isPrime(i)) {
			if (isPrime(i+2) && i <= N-2) {
				count ++;
			}
		}
		i ++;
	}
	cout << count;
	return 0;
}
