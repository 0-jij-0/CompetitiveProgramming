#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> res, diff;

bool build(int &n) {
	int x = 0;
	res.resize(n, 1);
	for (int i = 0; i < n; i++) {
		x ^= v[i][0];
	}
	if (x != 0) { return true; }
	else {
		int i = 0;
		for (; i < n; i++) {
			if (diff[i] != -1) { res[i] = diff[i] + 1; break; }
		}
		if (i != n) { return true; }
	}
	return false;
}

int main() {
	int n, m; cin >> n >> m;
	v.resize(n); diff.resize(n, -1);
	for (int i = 0; i < n; i++) { v[i].resize(m); }

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (j != 0 && diff[i] == -1 && v[i][j] != v[i][j - 1]) { 
				diff[i] = j;
			}
		}
	}

	bool b = build(n);
	if (!b) { cout << "NIE" << endl; }
	else {
		cout << "TAK" << endl;
		for (int i = 0; i < n; i++) {
			cout << res[i];
			if (i + 1 != n) { cout << " "; }
		}
		cout << endl;
	}
	cin.ignore(2); return 0;
}