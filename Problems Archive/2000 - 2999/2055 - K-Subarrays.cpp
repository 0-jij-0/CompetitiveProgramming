#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> v, pref, suff;
map<int, vector<int>> freq;

int main() {
	freopen("sub.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; v.resize(n); freq.clear();
		for (int i = 0; i < n; i++) { 
			cin >> v[i]; freq[v[i]].push_back(i);
		}
		
		pref.resize(n); pref[0] = v[0];
		for (int i = 1; i < n; i++)
			pref[i] = max(pref[i - 1], v[i]);

		suff.resize(n); suff[n - 1] = v[n - 1];
		for (int i = n - 2; i >= 0; i--)
			suff[i] = min(suff[i + 1], v[i]);
		
		int cur = 0;
		for (int i = 1; i < n; i++)
			cur += pref[i - 1] < suff[i];

		cout << (cur < k - 1 ? "NO" : "YES") << '\n';
	}
}