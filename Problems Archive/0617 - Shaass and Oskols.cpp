#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }

	int m; cin >> m;
	while (m--) {
		int x, y; cin >> x >> y; x--; y--;
		if (x != 0) { v[x - 1] += y; }
		if (x != n - 1) { v[x + 1] += v[x] - y - 1; }
		v[x] = 0;
	}
	for (auto &x : v) { cout << x << endl; }
	cin.ignore(2); return 0;
}