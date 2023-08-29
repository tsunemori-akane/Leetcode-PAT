#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct msg {
	int t, seat;
	string num;
};

bool cmp(msg a, msg b) {
	return a.t < b.t;
}

int main() {
	int n, m, test;
	cin >> n;
	vector<msg> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].num >> v[i].t >> v[i].seat;
	}
	sort(v.begin(), v.end(), cmp);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> test;
		cout << v[test-1].num << " " << v[test-1].seat << endl;
	}
	return 0;
}
