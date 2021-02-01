#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	int res = 0;
	if (e < f) {
		int x = min(b, min(c, d));
		res += f * x; d -= x;
		res += e * min(a, d);
	}
	else {
		int x = min(a, d);
		res += e * x; d -= x;
		res += f * min(b, min(c, d));
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}