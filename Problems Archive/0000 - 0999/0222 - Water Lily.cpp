#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	long long h, l; cin >> h >> l;
	long long a = l * l - h * h;
	long double res = (a + 0.0) / (2 * h + 0.0);
	cout << fixed << setprecision(10) << res << endl;
	cin.ignore(2); return 0;
}