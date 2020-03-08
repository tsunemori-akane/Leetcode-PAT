#include<iostream>
#include<string>

using namespace std;

int main() {
	int A, B, D, Q;
	string r;
	cin >> A >> B >> D;
    if ((A + B) < D) {
		cout << A + B;
		return 0;
	}
	Q = (A + B) / D;
	r = to_string((A + B) % D);
	if (Q < D) r = to_string(Q) + r;
	while (Q >= D) {
        r = to_string(Q % D) + r;
		Q = Q / D;
		if (Q < D) r = to_string(Q) + r;
	}
	cout << r;
	return 0;
}

