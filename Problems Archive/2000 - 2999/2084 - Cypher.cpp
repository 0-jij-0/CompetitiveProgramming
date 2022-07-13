#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> v; string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }

		for (int i = 0; i < n; i++) {
			int d; cin >> d >> s;
			int U = count(s.begin(), s.end(), 'U');
			int D = count(s.begin(), s.end(), 'D');
			v[i] = U > D ? (v[i] - (U - D) + 10) % 10 : (v[i] + (D - U)) % 10;
		}

		for (auto& x : v) cout << x << ' '; cout << '\n';
	}
}