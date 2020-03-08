#include<iostream>

using namespace std;

int main() {
	char c;
	int N, n = 1;
	cin >> N >> c;
	while((n+1)*(n+1)<=2*N+2) n+=2;//求出第一行符号数量n-2；
	for (int i = 0; n-2-2*i >= 1; i++) {
		for (int space = 0; space < i; space++) cout << " ";
		for (int ch = 0; ch < n-2-2*i; ch++) cout << c;
		cout << endl;
	}
	for (int i = 0; 3+2*i <= n-1; i++) {
		for (int space = (n-4-2*i)/2; space > 0; space--) cout << " ";
		for (int ch = 0; ch < 3+2*i; ch++) cout << c;
		cout << endl;
	}
	cout << N-(n-1)*(n-1)/2+1 ;
	return 0;
}