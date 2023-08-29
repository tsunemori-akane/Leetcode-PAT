#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main() {
	string malfucKey, typeNeed, ch = ",-_.";
	getline(cin, malfucKey);
	getline(cin, typeNeed);
	for (int i = 0; i < typeNeed.size(); i++) {
		if (malfucKey.find(toupper(typeNeed[i])) == string::npos) {
			if(malfucKey.find('+') == string::npos) 
				cout << typeNeed[i];
			else if (typeNeed[i] >= 'a' &&  typeNeed[i] <= 'z')
				cout << typeNeed[i];
			else if (ch.find(typeNeed[i]) != string::npos) cout << typeNeed[i];
			else if (isdigit(typeNeed[i])) cout << typeNeed[i];
		}
	}
	return 0;
}
