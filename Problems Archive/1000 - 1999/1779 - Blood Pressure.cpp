#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	double res = b + (a - b) / 3.0;
	cout << fixed << setprecision(6) << res << '\n';
	cin.ignore(2); return 0;
}