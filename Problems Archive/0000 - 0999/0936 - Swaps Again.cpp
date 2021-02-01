#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n; a.resize(n); b.resize(n);
		for (auto &x : a) { cin >> x; }
		for (auto &x : b) { cin >> x; }

		if (n % 2 && a[n / 2] != b[n / 2]) { cout << "No" << '\n'; continue; }
		multiset<int> A(a.begin(), a.end()), B(b.begin(), b.end());
		if (A.size() != B.size()) { cout << "No" << '\n'; continue; }
		auto itA = A.begin(), itB = B.begin(); bool ok = true;
		while (itA != A.end()) if (*(itA++) != *(itB++)) { ok = false; break; }
		if (!ok) { cout << "No" << '\n'; continue; }

		vector<pair<int, int>> pA, pB;
		for (int i = 0; i < n / 2; i++) {
			if (a[i] > a[n - i - 1]) { swap(a[i], a[n - i - 1]); }
			if (b[i] > b[n - i - 1]) { swap(b[i], b[n - i - 1]); }
			pA.emplace_back(a[i], a[n - 1 - i]);
			pB.emplace_back(b[i], b[n - 1 - i]);
		}
		sort(pA.begin(), pA.end());
		sort(pB.begin(), pB.end());
		for(int i = 0; i < n / 2; i++)
			if (pA[i] != pB[i]) { ok = false; break; }
		cout << (ok ? "Yes" : "No") << '\n';
	}
	cin.ignore(2); return 0;
}