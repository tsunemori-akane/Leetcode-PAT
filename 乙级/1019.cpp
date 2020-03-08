/*
**answer by liuchuo
*/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
bool cmp(char a, char b) {
	return a > b;
}

int main() {
	string s, des, asc;
	cin >> s;
	s.insert(0, 4-s.size(), '0');
	do {
		des = s; asc = s;
		sort(des.begin(), des.end(), cmp);
		sort(asc.begin(), asc.end());
		int result = stoi(des) - stoi(asc);
		s = to_string(result);
		s.insert(0, 4-s.size(), '0');
		cout << des << " - " << asc << " = " << s << endl;
	}
	while (s != "6174" && s != "0000");
	return 0;
}
