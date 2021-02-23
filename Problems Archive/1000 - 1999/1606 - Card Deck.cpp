#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, pref;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); pref.resize(n);
		for (auto& x : v) { cin >> x; }

		pref[0] = 0; for (int i = 1; i < n; i++)
			pref[i] = (v[i] > v[pref[i - 1]]) ? i : pref[i - 1];

		vector<int> res; int i = n; while (i) {
			for (int j = pref[i - 1]; j < i; j++)
				res.push_back(v[j]);
			i = pref[i - 1];
		}
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}