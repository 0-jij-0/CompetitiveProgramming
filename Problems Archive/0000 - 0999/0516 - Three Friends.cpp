#include <iostream>
#include <algorithm>
using namespace std;

int d[3];

int main() {
	int q; cin >> q;
	while (q--) {
		cin >> d[0] >> d[1] >> d[2];
		sort(d, d + 3);
		if (d[2] > d[1]) { d[2]--; }
		else if (d[2] == d[1] && d[1] > d[0]) { d[2]--; d[1]--; }
		if (d[0] < d[1]) { d[0]++; }
		else if (d[0] == d[1] && d[1] < d[2]) { d[0]++; d[1]++; }
		cout << 2 * (d[2] - d[0]) << endl;
	}
	cin.ignore(2); return 0;
}