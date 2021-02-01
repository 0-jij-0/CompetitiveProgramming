#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		vector<int> idx[10]; int n = (int)s.size();
		for (int i = 0; i < n; i++) { idx[s[i] - '0'].push_back(i); }
		int res = n; for (int i = 0; i < 10; i++) if(!idx[i].empty()) {
			res = min(res, n - (int)idx[i].size());
			for (int j = i + 1; j < 10; j++) if(!idx[j].empty()){
				bool b = idx[i].front() < idx[j].front(); int ans = 1;
				int last = b ? idx[i].front() : idx[j].front();
				while (true) {
					int k = b ? j : i;
					auto it = lower_bound(idx[k].begin(), idx[k].end(), last);
					if (it == idx[k].end()) { break; }
					b ^= 1; last = *it; ans++; continue;
				}
				res = min(res, n - ans + (ans & 1));
			}
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}