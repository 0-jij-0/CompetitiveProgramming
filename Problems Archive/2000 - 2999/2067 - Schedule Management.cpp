#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int n, m;

bool check(int k, vector<int>& freq) {
	ll res = 0; for (auto& x : freq) {
		if (x >= k) { res += k; continue; }
		res += x + ((k - x) / 2);
	}
	return res >= m;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n >> m; vector<int> freq(n);
		for (int i = 0; i < m; i++) {
			int x; cin >> x; freq[x - 1]++;
		}
		
		int l = 0, r = m << 1; while (l != r) {
			int mid = (l + r) >> 1;
			check(mid, freq) ? r = mid : l = mid + 1;
		}

		cout << l << '\n';
	}
}