#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> c, res;

int main() {
	int n, m, d; cin >> n >> m >> d; 
	c.resize(m); res.resize(n, 0); int s = 0;
	for (auto &x : c) { cin >> x; s += x; }
	int y = n - s;
	if (y / (m+1) > d - 1 || (y /(m + 1) == (d - 1) && y % (m + 1))) { cout << "NO" << endl; }
	else {
		int a = y / (m + 1), b = y % (m + 1), i = 0, j = 0;
		if (b) { i += a + 1; b--; }	else { i += a; }
		while (i != n) {
			while (c[j] != 0) { res[i] = j + 1; i++; c[j]--; }
			if (b) { i += a + 1; b--; j++; }
			else { i += a; j++; }
		}
		cout << "YES" << endl;
		for (auto &x : res) { cout << x << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}