#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> freq;

bool check() {
	for (auto &x : freq) {
		if (x.size() < 2) { continue; }
		if (x.size() > 2) { return true; }
		if (x[1] - x[0] != 1) { return true; }
	}
	return false;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; 
		freq.clear(); freq.resize(n + 1);
		for (int i = 0; i < n; i++) {
			int a; cin >> a; freq[a].push_back(i);
		}
		cout << (check() ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}