#include<iostream>
#include<string>

using namespace std;
int main() {
	string A, B;
	int pa=0, da, pb=0, db, cnta = 0, cntb = 0;
	cin >> A >> da >> B >> db;
	for (int i = 0; i < A.size(); i++) {
		if(A[i]-'0' == da) cnta++;
	}
	for (int i = 0; i < B.size(); i++) {
		if(B[i]-'0' == db) cntb++;
	}
	for (int i = 0; i < cnta; i++) {
		pa = pa*10 + da;
	}
	for (int i = 0; i < cntb; i++) {
		pb = pb*10 + db;
	}
	cout << pa + pb ;
	return 0;
}
