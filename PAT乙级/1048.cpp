/*
**inspired by liuchuo
*/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string A, B, r;
	char ch[3] = {'J', 'Q', 'K'};
	cin >> A >> B;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	if (A.size() > B.size()) B.append(A.size()-B.size(), '0');
	else A.append(B.size()-A.size(), '0');
	for (int i = 0; i < B.size(); i++) {
		if ((i+1)%2 != 0) {
			if (A[i]-'0' + B[i]-'0' > 9 && A[i]-'0' + B[i]-'0' < 13) {
				r += ch[A[i]-'0'+B[i]-'0'-10] ;
				continue;
			}
			r += ((A[i]-'0')+(B[i]-'0'))%13 + '0' ;
		}
		else {
			r += ((B[i]-'0')-(A[i]-'0')+10)%10 + '0';
		}
	}
	for (int i = r.size()-1; i >= 0; i--) cout << r[i];
}
