#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> v;

int main() {
	int n, m; cin >> n >> m; v.resize(n);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) { v[i].resize(m, '#'); continue; }
		v[i].resize(m, '.');
		((i % 4 == 1) ? v[i][m - 1] : v[i][0]) = '#';
	}
	for (auto &x : v) {
		for (auto &y : x) { cout << y; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}