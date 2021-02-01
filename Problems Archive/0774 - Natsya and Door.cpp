#include <iostream>
#include <vector>
using namespace std;

vector<int> v, peaks;

int main() {
	int t; cin >> t;
	while (t--) {
		v.clear(); peaks.clear();
		int n, k; cin >> n >> k; v.resize(n);
		for (auto &x : v) { cin >> x; }
		for (int i = 1; i < n - 1; i++)
			if (v[i] > v[i - 1] && v[i] > v[i + 1]) { peaks.push_back(i); }

		peaks.push_back(n + 1);
		int resL = 0, res = 0, ans = 0, i = 0, j = 0; bool peak = false;
		while (i < k) {
			if (peak) { peak = false; ans++; }
			if (i == peaks[j]) { peak = true; j++; }
			i++;
		}

		res = ans; int l = 0;
		while (i < n) {
			if (peak) { peak = false; ans++; }
			if (i - k + 1 == peaks[l]) { ans--; l++; }
			if (i == peaks[j]) { peak = true; j++; }
			if (ans > res) { resL = i - k + 1; res = ans; }
			i++;
		}
		cout << res + 1 << ' ' << resL + 1 << endl;
	}
	cin.ignore(2); return 0;
}