#include<iostream>
#include<string>

using namespace std;

string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"****", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string s;

void func() {
	string s1, s2;
	int d1=0, d2=0, d;
	s1 = s.substr(0, 3);
	int len = s.size();
	if (len > 4) s2 = s.substr(4, 3);
	for (int i = 0; i < 13; i++) {
		if (s1 == a[i] || s2 == a[i]) d1 = i;
        if (s1 == b[i]) d2 = i;
	}
	d = d2 * 13 + d1;
	cout << d ;
}

int main() {
	int n, r;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		if (s[0] >= 'a' && s[0] <= 'z') {
			func();
		} else {
			r = stoi(s);
			if (r/13 == 0) cout << a[r];
			else if (r%13 == 0){
				cout << b[r/13];
			}
			else
				cout << b[r/13] << " " << a[r%13];
		}
		cout << endl;
	}
	return 0;
}

