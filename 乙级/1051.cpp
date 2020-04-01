#include<iostream>
#include<cmath>

using namespace std;

int main() {
	double r1, r2, p1, p2, A, B;
	scanf("%lf%lf%lf%lf", &r1, &p1, &r2, &p2);
	A = r1 * cos(p1) * r2 * cos(p2) - r1 * sin(p1) * r2 * sin(p2);
	B = r1 * cos(p1) * r2 * sin(p2) + r1 * sin(p1) * r2 * cos(p2);
	if (fabs(A) < 0.01) A = 0.00;
	if (fabs(B) < 0.01) B = 0.00;
	if (B >= 0) printf("%.2lf+%.2lfi", A, B);
	else printf("%.2lf%.2lfi", A, B);
	return 0;
}
