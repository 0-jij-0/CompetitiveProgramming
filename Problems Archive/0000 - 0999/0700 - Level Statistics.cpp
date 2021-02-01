#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> &v) {
	for (int i = 1; i < (int)v.size(); i++)
		if (v[i] < v[i - 1]) return false;

	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; vector<int> p(n), c(n);
		for (int i = 0; i < n; i++) { cin >> p[i] >> c[i]; }
		if (!checkSorted(p) || !checkSorted(c)) { cout << "NO" << endl; continue; }
		bool b = c[0] <= p[0]; if (!b) { cout << "NO" << endl; continue; }
		for (int i = 1; i < n; i++) {
			if (c[i] > p[i]) { b = false; break; }
			//if (p[i] - p[i - 1]  < c[i] - c[i - 1]) { b = false; break; }
			if (p[i] == p[i - 1] && c[i] != c[i - 1]) { b = false; break; }
		}
		cout << (b ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}