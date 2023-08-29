#include<iostream>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

struct p {
	string name;
	int height;
};

bool cmp(p a, p b) {
	return (a.height != b.height) ? (a.height > b.height) : (a.name < b.name);
}

int main() {
	int N, K;
	cin >> N >> K;
	p t[10000];
	for (int i = 0; i < N; i++) {
		cin >> t[i].name >> t[i].height; 
	}
	sort(t, t+N, cmp);
	int count = 0, lastRow = N / K + N % K, row = N / K;
	for (int i = 0; i < K; i++) {
		list<string> a;
		for (int j = 0; j < (i == 0 ? lastRow : row); j++) {
			if (j % 2 == 0) {
				a.push_back(t[count].name);
			}
			else a.push_front(t[count].name);
			count++;
		}
		list<string>::iterator it = a.begin();
		cout << *it++;
		while(it != a.end() ) {
			cout << " " << *it ;
			it++;
		}
		cout << endl;
	}
	return 0;
}
