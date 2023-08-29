#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		long long int  A, B, C;
		cin >> A >> B >> C;
		cout << "Case #" << i+1 << ": " << boolalpha << (A + B > C) ? "":"" ;
        cout << endl;
	}
	return 0;
}