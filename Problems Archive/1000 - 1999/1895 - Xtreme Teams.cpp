#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

vector<int> freq, v;

int toBinary(string& s) {
	int res = 0;
	for (auto& x : s) { res = (res << 1) + (x == 'y'); }
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; freq.clear(); v.clear();
		freq.resize(1 << m); v.resize(n);
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			freq[v[i] = toBinary(s)]++;
		}

		for (int i = 0; i < (1 << m); i++) if (freq[i])
			for (int s = i; s; s = (s - 1) & i)
				if (s != i) freq[s] += freq[i];

		int req = (1 << m) - 1; ll res = 0;
		for(int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++) {
				int t = v[i] | v[j], rem = req ^ t;
				res += (rem == 0 ? n - 2 : freq[rem]);
			}

		cout << res / 3 << '\n';
	}
	cin.ignore(2); return 0;
}

	