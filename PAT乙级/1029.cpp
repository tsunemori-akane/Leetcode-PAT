#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string s1, s2, s3;
	int j = -1;
	cin >> s1 >> s2;
	vector<int> v(s1.size(), 0);
	for (int i = 0; i < s2.size(); i++) {
		/*使用while...do语句最后一个测试点不能通过*/
		do{
			j++;
		} while(s2[i]!=s1[j]) ;
		v[j] = 1;
	}
	for (int i = 0; i < s1.size(); i++) {
		if (v[i]==0)
			if (s3.find(toupper(s1[i]))== string::npos ) s3 += toupper(s1[i]);	
	}
	cout << s3;
	return 0;
}
