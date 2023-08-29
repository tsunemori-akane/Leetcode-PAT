#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	int cnt[10] = {0};
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		cnt[s[i] - '0'] ++;
	}
	for (int i = 0; i < 10; i ++) {
		if (cnt[i] != 0) cout << i << ":" << cnt[i] << endl;
	}
	return 0;
}
