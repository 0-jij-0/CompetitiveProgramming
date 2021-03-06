#include <iostream>
#include <iomanip>
using namespace std;
typedef double ld;

int main() {
	int n; cin >> n;
	ld res = 0.0;; int i = 1;
	while (i < n) { res += 1.0 / i++; }
	cout << fixed << setprecision(10) << n * res << '\n';
	cin.ignore(2); return 0;
}