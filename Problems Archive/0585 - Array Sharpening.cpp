#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		int i = 0;
		for (; i < n; i++) {
			if (v[i] >= i) {continue; }
			break;
		}
		for (; i < n; i++) {
			if (v[i] >= v[i - 1]) { v[i] = v[i - 1] - 1; }
			if (v[i] < 0) { break; }
			if (v[i] == 0) { i++; break; }
		}
		cout << (i == n ? "Yes" : "No") << endl;
	}
	cin.ignore(2); return 0;
}