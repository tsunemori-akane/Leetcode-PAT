#include<iostream>

using namespace std;

int main(){
	int n, b, s, g;
	cin >> n;
	b = n / 100;
	s = (n / 10) % 10;
	g = n % 10;
	if(0 < n < 1000) {
		for (int i = 0; i < b; i ++) {
			cout << "B";
		}
		for (int i = 0; i < s; i ++) {
			cout << "S";
		}
		for (int i = 1; i <= g; i ++) {
			cout << i;
		}
	}
}