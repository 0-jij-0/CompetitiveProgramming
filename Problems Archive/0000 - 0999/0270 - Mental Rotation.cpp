#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<char>> v;
string s;

int main() {
	int n; cin >> n >> s; v.resize(n);
	for (int i = 0; i < n; i++) { v[i].resize(n); }
	int l = 0, r = 0;
	for (auto &c : s) {
		if (c == 'L') { l++; }
		else { r++; }
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c; cin >> c; v[i][j] = c;
		}

	int x = abs(l - r) % 4;

	if (x == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << v[i][j];
			}
			cout << endl;
		}
	}
	else if (x == 2) {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (v[i][j] == '.') { cout << '.'; }
				else if (v[i][j] == '^') { cout << 'v'; }
				else if (v[i][j] == 'v') { cout << '^'; }
				else if (v[i][j] == '>') { cout << '<'; }
				else { cout << '>'; }
			}
			cout << endl;
		}
	}
	else if ((x == 1 && l > r) || (x == 3 && r > l)) {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (v[j][i] == '.') { cout << '.'; }
				else if (v[j][i] == '^') { cout << '<'; }
				else if (v[j][i] == 'v') { cout << '>'; }
				else if (v[j][i] == '>') { cout << '^'; }
				else { cout << 'v'; }
			}
			cout << endl;
		}
	}
	else if ((x == 1 && r > l) || (x == 3 && l > r)) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (v[j][i] == '.') { cout << '.'; }
				else if (v[j][i] == '^') { cout << '>'; }
				else if (v[j][i] == 'v') { cout << '<'; }
				else if (v[j][i] == '>') { cout << 'v'; }
				else { cout << '^'; }
			}
			cout << endl;
		}
	}
	cin.ignore(2); return 0;
}