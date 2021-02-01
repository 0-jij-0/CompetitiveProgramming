#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
vector<long long> pref;

int main() {
	int m; cin >> m;
	while (m--) {
		int n, t, a, b; cin >> n >> t >> a >> b;
		v.clear(); pref.clear(); v.resize(n); 
		int ec = 0, hc = 0;
		for (auto &x : v) { cin >> x.second; (x.second ? hc : ec)++; }
		for (auto &x : v) { cin >> x.first; }
		sort(v.begin(), v.end()); 
		pref.resize(n); long long pre = 0;
		for (int i = 0; i < n; i++) {
			pre += v[i].second ? b : a;
			pref[i] = pre;
		}
		if (pref.back() <= t) { cout << n << endl; continue; }
		int i = 0; int res = 0;
		int fe = min((v[0].first - 1) / a, ec);
		int fh = min((v[0].first - 1 - fe * a) / b, hc);
		res = max(fe + fh, 0);
		while (i < n && pref[i] <= t) {
			(v[i].second ? hc : ec)--;
			if (pref[i] < v[i + 1].first) { 
				int cur = i + 1;
				long long rem = v[i + 1].first - 1 - pref[i];
				int e = min(ec, (int)(rem / a));
				int h = min(hc, (int)((rem - a * e) / b));
				cur += e + h; res = max(res, cur);
			}
			i++;
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}