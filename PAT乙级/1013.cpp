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
	int M, N, p = 1, count = 0;
	cin >> M >> N;
	while(count < M) {
		if(isPrime(p)) {
			count ++;
		}
		p++;
	}
	cout << p-1;
	while(count < N) {
		if (isPrime(p)) {
			count++;
            if ((count-M+1) % 10 != 1) printf(" ");
			cout << p;
            if ((count-M+1) % 10 == 0) printf("\n");
		}
		p++;
	}
	return 0;
}