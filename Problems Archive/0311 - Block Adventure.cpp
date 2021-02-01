#include <iostream>
#include <vector>
using namespace std;

vector<int> h;
int n, m, k;

bool check() {
	for (int i = 0; i < n - 1; i++) {
		int dif = abs(h[i] - h[i + 1]);
		if (dif > k && h[i] < h[i + 1]) {
			if (dif - k > m) { return false; }
			m -= dif - k; continue;
		}
		int a = h[i + 1] - k;
		if (a < 0) { m += h[i]; }
		else { m += h[i] - a; }
	}
	return true;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> k;
		h.clear(); h.resize(n);
		for (auto &x : h) { cin >> x; }
		bool b = check();
		if (b) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	cin.ignore(2); return 0;
}