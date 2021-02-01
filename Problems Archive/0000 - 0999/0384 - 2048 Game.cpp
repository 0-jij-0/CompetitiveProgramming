#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

int main() {
	int q; cin >> q;
	while (q--) {
		int n; cin >> n; v.clear();
		for (int i = 0; i < n; i++) {
			long long a; cin >> a;
			if (a > 2048) { continue; }
			v.push_back(a);
		}
		n = (int)v.size();
		long long sum = 0; for (auto &x : v) { sum += x; }
		cout << ((sum >= 2048) ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}