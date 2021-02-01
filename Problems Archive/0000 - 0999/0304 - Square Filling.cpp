#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> a, b;
int n, m;

bool eq(int i, int j) {
	return (a[i][j] == b[i][j]) && (a[i + 1][j] == b[i + 1][j]) && (a[i][j + 1] == b[i][j + 1]) && (a[i + 1][j + 1] == b[i + 1][j + 1]);
}

bool onesquare(int i, int j) {
	return ((a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1]) == 4);
}

void set(int i, int j) {
	b[i][j] = a[i][j]; b[i + 1][j] = a[i + 1][j]; b[i][j + 1] = a[i][j + 1]; b[i + 1][j + 1] = a[i + 1][j + 1];
}

bool check() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] != b[i][j])
				return false;
	return true;
}
void makeAeqB() {
	vector<pair<int, int>> res;
	for(int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			if (onesquare(i, j)) {
				set(i, j); res.push_back({ i + 1, j + 1 });
			}

	bool b = check(); if (!b) { cout << -1 << endl; return; }

	cout << res.size() << endl;
	for (auto &x : res) { cout << x.first << ' ' << x.second << endl; }
}

int main() {
	cin >> n >> m; a.resize(n); b.resize(n);
	for (int i = 0; i < n; i++) { a[i].resize(m); }
	for (int i = 0; i < n; i++) { b[i].resize(m, 0); }
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	makeAeqB();
	cin.ignore(2); return 0;
}