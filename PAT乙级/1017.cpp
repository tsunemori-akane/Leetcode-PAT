#include<iostream>
#include<string>

using namespace std;

int main() {
	string A, Q;
	int B, r = 0;
	cin >> A >> B;
	for (int i = 0; i < A.size(); i++) {
		Q += to_string((A[i]-'0' + r*10) / B);
		r = (A[i]-'0' + r*10) % B;
	}
	if (Q[0] == '0' && Q.size() > 1) {
		Q = Q.substr(1, Q.size()-1);
	}
	cout << Q << " " << r;
	return 0;
}
