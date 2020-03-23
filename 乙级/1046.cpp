#include<iostream>

using namespace std;

int main() {
	int n, a1, a2, b1, b2, cnt1=0, cnt2=0;
	cin >> n;
	for (int i = 0; i < n ; i++) {
		cin >> a1 >> a2 >> b1 >> b2;
		if (a2 == a1 + b1 && b2 != a1 + b1) cnt2++;
		if (a2 != a1 + b1 && b2 == a1 + b1) cnt1++;
	}
	cout << cnt1 << " " << cnt2;
}
