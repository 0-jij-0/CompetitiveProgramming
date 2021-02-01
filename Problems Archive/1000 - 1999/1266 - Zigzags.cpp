#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<vector<int>> freq;
vector<int> v;

ll choose4(ll x) { return x * (x - 1) * (x - 2) * (x - 3) / 24; }
ll choose2(ll x) { return x * (x - 1) / 2; }

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); freq.clear();
		freq.resize(n, vector<int>(n + 1, 0));
		for (int i = 0; i < n; i++) {
			int x; cin >> x; x--; v[i] = x;
			freq[x][0]++; freq[x][i + 1]--;
		}

		for (int i = 0; i < n; i++)
			partial_sum(freq[i].begin(), freq[i].end(), freq[i].begin());

		vector<ll> C2(n, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				C2[i] += choose2(freq[j][i]);

		ll same = 0, all = 0;

		for (int i = 0; i < n; i++) {
			same += choose4((ll)freq[i][0]);
			for (int j = i + 3; j < n; j++) if (v[i] != v[j])
				all += (freq[v[i]][i + 1] - freq[v[i]][j]) * (freq[v[j]][i] - freq[v[j]][j]);
		}
	
		ll res = all;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
				if (v[i] == v[j]) { res -= (j + 1 != n) ? C2[j + 1] : 0; }
		}

		cout << res + 2 * same << '\n';
	}
	cin.ignore(2); return 0;
}