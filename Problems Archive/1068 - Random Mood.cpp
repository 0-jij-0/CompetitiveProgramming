#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n; double p; cin >> n >> p;
	cout << fixed << setprecision(10) << (1 + pow(1.0 - 2 * p, n + 0.0)) / 2 << endl;
	cin.ignore(2); return 0;
}