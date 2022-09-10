#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

vector<int> a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		a.resize(n); for (auto& x : a) cin >> x;
		b.resize(n); for (auto& x : b) cin >> x;
		multiset<int> A(a.begin(), a.end());
		multiset<int> B(b.begin(), b.end());

		int res = 0; while (!A.empty()) {
			auto iA = A.rbegin(), iB = B.rbegin();
			if (*iA == *iB) { A.erase(--A.end()); B.erase(--B.end()); continue; }
			if (*iA > *iB) { res++; A.insert(to_string(*iA).size()); A.erase(--A.end()); }
			else { res++; B.insert(to_string(*iB).size()); B.erase(--B.end()); }
		}

		cout << res << '\n';
	}
}