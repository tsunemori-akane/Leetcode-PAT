#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    string s1, s2;
    int cnt = 0;
    vector<int> c(128, 0);
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) c[s1[i]]++;
	for (int i = 0; i < s2.size(); i++) c[s2[i]]--;
	sort(c.begin(), c.end());
	if (c[0] < 0){
		for (int i = 0; c[i] < 0 ; i++) cnt -= c[i];
		cout << "No" << " " << cnt; 
	} else {
		cout << "Yes" << " " << s1.size() - s2.size();
	}
	return 0;
}

