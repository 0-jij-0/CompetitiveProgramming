#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

string s; vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s; v.resize(n);
		
		ll cur = 0; for (int i = 0; i < n; i++) {
			int L = i, R = n - 1 - i;
			cur += (s[i] == 'L') ? L : R;
			v[i] = (s[i] == 'L') ? R - L : L - R;
		}

		sort(v.rbegin(), v.rend());
		for(int i = 0; i < n; i++)
			if (v[i] < 0) { cout << cur << ' '; }
			else { cout << (cur += v[i]) << ' '; }
		cout << '\n';
	}
}