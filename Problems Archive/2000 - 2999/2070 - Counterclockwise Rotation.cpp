#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
typedef double ld;
const ld PI = 3.14159265358979;

int main() {
	int x, y, d; cin >> x >> y >> d;
	ld D = d * PI / 180.0;
	cout << fixed << setprecision(6);
	cout << x * cos(D) - y * sin(D) << ' ';
	cout << x * sin(D) + y * cos(D) << '\n';
}