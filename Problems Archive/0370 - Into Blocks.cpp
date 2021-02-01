#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> v, freq;
map<int, int> m;

int main() {
	int n, q; cin >> n >> q;
	v.resize(n); freq.resize(200001, 0);
	for (auto &x : v) { cin >> x; freq[x]++; }
	int res = 0;
	for (int i = 0; i < n; i++) {
		m[v[i]] = freq[v[i]]; int ma = freq[v[i]], j = i;
		while (i < n && !m.empty()) {
			if (m[v[i]] != 0) { 
				m[v[i]]--; if (!m[v[i]]) { m.erase(v[i]); }
			}
			else { 
				ma = max(ma, freq[v[i]]);
				if (freq[v[i]] == 1) { m.erase(v[i]); i++; continue; }
				m[v[i]] = freq[v[i]] - 1;
			}
			i++;
		}
		res += i - j - ma; i--;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}