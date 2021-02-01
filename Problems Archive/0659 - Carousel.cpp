#include <iostream>
#include <vector>
using namespace std;

vector<int> v, c;
int res;

void check() {
	if (v.back() == v.front()) { return; }
	if (c.front() != c.back()) { return; }
	int n = (int)v.size();
	if (v[n - 1] == v[n - 2]) { c[n - 1] = (c[n - 2] == 2) ? 1 : 2; return; }
	if (v[0] == v[1]) { c[0] = 2; return; }
	c[n - 1] = 3; res = 3; return;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }

		int idx = 0;
		for (idx = 0; idx < n - 1; idx++) {
			if (v[idx] == v[idx + 1]) { break; }
		}

		if (idx != n) {
			vector<int> temp;
			for (int j = 0; j < n; j++)
				temp.push_back(v[(idx + j) % n]);

			v = move(temp);
		}
		c.resize(n); c[0] = 1; bool two = false;
		for (int i = 1; i < n; i++) {
			if (v[i] == v[i - 1]) { c[i] = c[i - 1]; continue; }
			c[i] = c[i - 1] == 1 ? 2 : 1; two = true;
		}
		res = 1 + two;
		check(); cout << res << endl;

		for (int j = 0; j < n; j++) { 
			cout << c[(n - idx + j) % n] << ' ';
		}
		cout << endl;
	}
	cin.ignore(2); return 0;
}