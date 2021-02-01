#include <iostream>
using namespace std;

int main() {
	long long a, b, c; cin >> a >> b >> c;
	long long len = 2 * c;
	long long min = (a < b) ? a : b;
	a -= min; b -= min;
	len += 2 * min;
	if (a != 0 || b != 0) { len++; }
	cout << len << endl;
	cin.ignore(2); return 0;
}