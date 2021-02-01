#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

string s;
map<pair<int, int>, vector<int>> m;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n >> s; m.clear();
		int x = 0, y = 0; m[{0, 0}].push_back(-1);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L') { x--; }
			if (s[i] == 'R') { x++; }
			if (s[i] == 'D') { y--; }
			if (s[i] == 'U') { y++; }
			m[{x, y}].push_back(i);
		}
		int L = -2, R = n + 1;
		for (auto &x : m) {
			if (x.second.size() < 2) { continue; }
			int s = (int) x.second.size();
			for (int i = 1; i < s; i++) {
				if (x.second[i] - x.second[i - 1] < R - L) {
					R = x.second[i]; L = x.second[i - 1];
				}
			}
		}
		if (L == -2) { cout << -1 << endl; continue; }
		cout << L + 2 << ' ' << R + 1 << endl;
	}
	cin.ignore(2); return 0;
}