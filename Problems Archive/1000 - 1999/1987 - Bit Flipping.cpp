#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k >> s;
		vector<int> res(n); char c = (k & 1) + '0';
		int i = 0, j = 0; while (i != n && j != k) {
			while (i != n && s[i] != c) i++;
			if (i != n) { j++; res[i++] = 1; }
		}

		res.back() += k - j;
		for (int x = 0; x < i; x++) s[x] = '1';
		if (k & 1) for (int x = i; x < n; x++) s[x] = (s[x] == '0') ? '1' : '0';
		if (i == n && ((j - k) & 1)) s[n - 1] = (s[n - 1] == '0' ? '1' : '0');

		cout << s << '\n';
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}

	cin.ignore(2); return 0;
}