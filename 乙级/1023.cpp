#include<iostream>
#include<string>

using namespace std;

int main() {
	int n, t = 0, r[10];
	string s1, s2;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		r[i] = n;
		t += n;
	}
	for (int i = 1; i < 10; i++) {
		if (r[0] == 0) {
			for (int j = 0; j < r[i]; j++) {
				cout << i;
			}
		}
		else {
			for (int j = 0; j < r[i]; j++) {
				s1 = s1 + to_string(i);
			}
		}
	}
	if (r[0] != 0) {
		while (r[0] > 0) {
			s2 = s2 + '0';
			r[0] --;
		}
		cout << s1[0] + s2 + s1.substr(1, t-1);
	}
	return 0;
}
