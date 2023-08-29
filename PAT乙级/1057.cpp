#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main() {
	int sum = 0, cnt0 = 0, cnt1 = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if(isalpha(s[i])) {
			sum += tolower(s[i]) - 'a' + 1 ;
		}
	}
	while(sum != 0) {
		if(sum % 2 == 1) cnt1 ++;
		else cnt0 ++;
		sum = sum / 2;
	}
	cout << cnt0 << " " << cnt1;
	return 0;
}
