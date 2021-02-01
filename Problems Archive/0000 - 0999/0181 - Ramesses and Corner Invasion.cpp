#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> g;
int n, m;

bool check() {
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = 0; j < m; j++) { s += g[i][j]; }
		if (s % 2) { return false; }
	}
	for (int i = 0; i < m; i++) {
		int s = 0;
		for (int j = 0; j < n; j++) { s += g[j][i]; }
		if (s % 2) { return false; }
	}
	return true;
}

int main() {
	cin >> n >> m; g.resize(n);
	for (int i = 0; i < n; i++) { g[i].resize(m); }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int b; cin >> b; g[i][j] = b;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int b; cin >> b; g[i][j] = g[i][j] ^ b;
		}
	}
	string res = (check()) ? "Yes" : "No";
	cout << res << endl;
	
	cin.ignore(2); return 0;
}
