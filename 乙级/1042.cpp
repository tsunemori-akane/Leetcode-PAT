#include<iostream>
#include<string>

using namespace std;

int main() {
	int a[128] = {0};
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		a[s[i]]++;
	}
	int temp = 0; 
	char alpha = 'A';
	for (int i = 65; i <= 90; i++) {
		if (a[i] + a[i+32] > temp) {
			temp = a[i] + a[i+32];
			alpha = 'A' + i - 65;
		}
	}
	alpha = alpha + 32;
	cout << alpha << " " << temp;
}
