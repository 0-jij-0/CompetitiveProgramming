#include <bits/stdc++.h>
using namespace std;

vector<string> v(8, "");

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		for (auto& x : v) cin >> x;

		bool red = false;
		for (auto& x : v)
			if (count(x.begin(), x.end(), 'R') == 8)
				red = true;

		cout << (red ? 'R' : 'B') << '\n';
	}
}