#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> res;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m; res.clear();
		res.resize(n, vector<char>(m, 'B'));
		res[0][0] = 'W';
		for (auto &x : res) {
			for (char&y : x) { cout << y; }
			cout << endl;
		}
	}
	cin.ignore(2); return 0;
}