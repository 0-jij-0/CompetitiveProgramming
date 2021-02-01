#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long double ld;
const ld pi = 3.141592653589793238;

int main() {
	ifstream ifs("baklava.in");
	int t; ifs >> t;
	while (t--) {
		int n; ifs >> n;
		ld r = (n - 2.0) / (n + 0.0);
		ld a = 0.5*(1 - cos(r*pi));
		cout << fixed << setprecision(5) << 10000.0 / (1.0 - a) << endl;
	}
	cin.ignore(2); return 0;
}