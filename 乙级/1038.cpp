#include<iostream>

using namespace std;

int main() {
	int n, score, k, s[101]={0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &score);
		s[score]++;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &score);
		printf("%d", s[score]);
        if (i != k-1) printf(" ");
	}
	return 0;
}
