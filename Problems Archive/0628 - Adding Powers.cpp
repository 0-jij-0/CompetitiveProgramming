#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<long long> v;

bool check(int k) {
	set<int> used;
	for (auto &x : v) {
		int i = 0;
		while (x) {
			if (x % k == 0) { x /= k; i++; continue; }
			if (x % k > 1 || used.count(i)) { return false; }
			used.insert(i); i++; x /= k;
		}
	}
	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k; v.resize(n);
		for (auto &x : v) { cin >> x; }
		cout << (check(k) ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}