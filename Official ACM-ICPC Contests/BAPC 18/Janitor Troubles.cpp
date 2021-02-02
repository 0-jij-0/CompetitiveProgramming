#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double maxArea(double a, double b, double c, double d) {
	double sp = (a + b + c + d) / 2;
	return sqrt((sp - a) * (sp - b) * (sp - c) * (sp - d));
}

int main() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	cout << fixed << setprecision(8) << maxArea(a, b, c, d) << endl;
	cin.ignore(2); return 0;
}