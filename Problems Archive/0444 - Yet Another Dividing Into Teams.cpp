#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s;

bool check() {
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] == s[i - 1] + 1) { return true; }
	}
	return false;
}

int main() {
	int q; cin >> q;
	while (q--) {
		int n; cin >> n; s.resize(n);
		for (auto &x : s) { cin >> x; }
		sort(s.begin(), s.end());
		cout << 1 + check() << endl;
	}
	cin.ignore(2); return 0;
}