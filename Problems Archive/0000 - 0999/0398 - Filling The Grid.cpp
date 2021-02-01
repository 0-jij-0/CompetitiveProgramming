#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1000 * 1000 * 1000 + 7;
vector<int> r, c; int h, w;

bool check() {
	vector<vector<int>> v(h, vector<int>(w, 0));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < r[i]; j++) {
			v[i][j] = 1;
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < c[i]; j++) {
			v[j][i] = 1;
		}
	}

	for (int i = 0; i < h; i++) {
		int x = 0, j = 0;
		while (j < w && v[i][j] == 1) { x++; j++; }
		if (x != r[i]) { return false; }
	}
	for (int i = 0; i < w; i++) {
		int x = 0, j = 0;
		while (j < h && v[j][i] == 1) { 
			x++; j++;
		}
		if (x != c[i]) { return false; }
	}
	return true;
}

int main() {
	cin >> h >> w; r.resize(h); c.resize(w);
	for (auto &x : r) { cin >> x; }
	for (auto &x : c) { cin >> x; }

	bool b = check();
	if (!b) { cout << 0 << endl; }
	else {
		long long res = 1;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (r[i] >= j) { continue; }
				if (c[j] >= i) { continue; }
				res <<= 1; res %= mod;
			}
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}