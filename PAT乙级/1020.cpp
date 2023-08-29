/*
**answer by liuchuo
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
struct mooncake {
	float n, price, unit_price;
};

int cmp(mooncake a, mooncake b) {
	return a.unit_price > b.unit_price;
}
int main() {
	int n, demand;
	cin >> n >> demand;
	vector<mooncake> a(n);
	for (int i = 0; i < n; i++) scanf("%f", &a[i].n);
	for (int i = 0; i < n; i++) scanf("%f", &a[i].price);
	for (int i = 0; i < n; i++) a[i].unit_price = a[i].price /a[i].n;
	sort(a.begin(), a.end(), cmp);
	float result = 0.0;
	for (int i = 0; i < n; i++) {
		if (a[i].n <= demand) {
			result = result + a[i].price;
		} else {
			result = result + a[i].unit_price * demand;
			break;
		}
		demand = demand - a[i].n;
	}
	printf("%.2f", result);
	return 0;
}




